/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:42:29 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/12 17:05:51 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_h_p_node	*head_ptr_arr = NULL;
	t_h_p_node			*head_ptr;
	char				*str;

	if (head_ptr_arr == NULL)
		head_ptr_arr = make_new_h_p_node(fd);
	head_ptr = search_fd_matching_head_ptr(fd, head_ptr_arr);
	if (head_ptr->head == NULL)
		head_ptr->head = make_new_node(head_ptr->fd);
	if (head_ptr->head == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (count_char_till_end(head_ptr) + 1));
	if (str == NULL)
		return (NULL);
	copy_char_from_buffer_to_str(head_ptr, str);
	termination_protocol(head_ptr);
	return (str);
}


/*
New head pointer node will be when there are no 
*/
t_h_p_node  *search_fd_matching_head_ptr(int fd, t_h_p_node *head_ptr_arr)
{
	t_h_p_node	*h_p_node;

	h_p_node = head_ptr_arr;
	while (TRUE)
	{
		if (h_p_node->fd == fd)
			return (h_p_node);
		else if (h_p_node->next == NULL)
		{
			h_p_node->next = make_new_h_p_node(fd);
			return (h_p_node->next);
		}
		else
			h_p_node = h_p_node->next;
	}
}

t_h_p_node	*make_new_h_p_node(int fd)
{
	t_h_p_node	*h_p_node;

	h_p_node = malloc(sizeof(t_h_p_node));
	h_p_node->fd = fd;
	h_p_node->head = NULL;
	h_p_node->next = NULL;
	return (h_p_node);
}

t_b_node	*make_new_node(int fd)
{
	t_b_node	*new_node;

	new_node = malloc(sizeof(t_b_node));
	if (new_node == NULL)
		return (NULL);
	new_node->read_cnt = read(fd, new_node->buffer, BUFFER_SIZE);
	if (new_node->read_cnt <= 0)
		return (NULL);
	new_node->start = new_node->buffer;
	new_node->end = ft_memchr(new_node->buffer, '\n', new_node->read_cnt);
	if (new_node->end == NULL && new_node->read_cnt < BUFFER_SIZE)
		new_node->end = new_node->buffer + new_node->read_cnt - 1;
	return (new_node);
}

/*
This function returns the number of character from start pointer to end pointer.
if end pointer is not in current searching buffer, make new node and link with 
current buff node and search next one. 
*/
size_t	count_char_till_end(t_h_p_node *head_ptr)
{
	t_b_node	*head;
	size_t		count;

	head = head_ptr->head;
	count = 0;
	while (TRUE)
	{
		if (head->end == NULL)  // when no new_line or no eof
		{
			count += BUFFER_SIZE - (head->start - head->buffer);
			head->next = make_new_node(head_ptr->fd);
			if (head->next == NULL)  // when the last char in buffer is eof -> next buffer will not be read proplerly
			{
				head->end = head->buffer + BUFFER_SIZE - 1;
				return (count);
			}
			else  // when next buffer is successfully read
				head = head->next;
		}
		else  // new_line or eof
		{
			count += head->end - head->start + 1;
			return (count);
		}
	}
}

/*
function from libft
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	temp_c;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	temp_c = (unsigned char)c;
	while (i < n)
	{
		if (p[i] == temp_c)
			return (p + i);
		i++;
	}
	return (NULL);
}

/*
Function from libft
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	if (src != dst)
	{
		temp_src = (unsigned char *)src;
		temp_dst = (unsigned char *)dst;
		i = 0;
		while (i < n)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}


void	copy_char_from_buffer_to_str(t_h_p_node *head_ptr, char *str)
{
	t_b_node	*b_node;
	size_t		cpy_range;

	b_node = head_ptr->head;
	while (TRUE)
	{
		if (b_node->end == NULL)  // copy from start to end of buffer
		{
			cpy_range = BUFFER_SIZE - (b_node->start - b_node->buffer);
			ft_memcpy(str, b_node->start, cpy_range);
			str += cpy_range;
			b_node = b_node->next;
		}
		else  // copy from start to end. 
		{
			cpy_range = b_node->end - b_node->start + 1;
			ft_memcpy(str, b_node->start, cpy_range);
			return ;
		}
	}
}

/*
erase buffer node from head to previous node of the last node. if 
*/

void	termination_protocol(t_h_p_node *head_ptr)
{
	t_b_node	*del_node;
	t_b_node	*h_node;
	size_t		sch_range;

	h_node = head_ptr->head;
	while (h_node->end == NULL && h_node->next != NULL)
	{
		del_node = h_node;
		h_node = h_node->next;
		free(del_node);
	}
	if (h_node->end == h_node->buffer + BUFFER_SIZE - 1)  // if end is the last character of buffer
		free(h_node);
	else
	{
		head_ptr->head = h_node;
		h_node->start = h_node->end + 1;
		sch_range = h_node->read_cnt - (h_node->start - h_node->buffer);
		h_node->end = ft_memchr(h_node->start, '\n', sch_range);
		if (h_node->end == NULL && h_node->read_cnt < BUFFER_SIZE)  // EOF
			h_node->end = h_node->buffer + h_node->read_cnt - 1;
	}
}

/*
Function from libft
*/
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;
	size_t			i;

	dst = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		dst[i] = (unsigned char)c;
		i++;
	}
	return (b);
}