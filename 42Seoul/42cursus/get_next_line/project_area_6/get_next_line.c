/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:51:32 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/13 16:13:53 by seoyoo           ###   ########.fr       */
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
		head_ptr->head = make_new_b_node(head_ptr->fd);
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
This function makes new head pointer node. 
*/
t_h_p_node	*make_new_h_p_node(int fd)
{
	t_h_p_node	*h_p_node;

	h_p_node = malloc(sizeof(t_h_p_node));
	h_p_node->fd = fd;
	h_p_node->head = NULL;
	h_p_node->next = NULL;
	return (h_p_node);
}

/*
This function makes new buffer pointing node which also has information about 
start index, end index, read count(result of read()), and next buffer node's 
address.
*/
t_b_node	*make_new_b_node(int fd)
{
	t_b_node	*new_node;

	new_node = malloc(sizeof(t_b_node));
	if (new_node == NULL)
		return (NULL);
	new_node->read_cnt = read(fd, new_node->buffer, BUFFER_SIZE);
	if (new_node->read_cnt <= 0)
		return (NULL);
	new_node->start = 0;
	new_node->end = find_closest_end(new_node);
	new_node->next = NULL;
	return (new_node);
}

/*
This function finds the cloest ending point from starting point. End point must 
be new line character('\n') or the last character of current fd.
WARNING : If current buffer's last character is the last character of current
file(EOF), end is still set to -1. Therefore, in this case, current buffer's end
will be -1 and next buffer will be null. Use this to make sure the function ends
properly. 
*/
ssize_t find_closest_end(t_b_node *buffer_node)
{
	ssize_t	idx;

	idx = buffer_node->start;
	while (idx < buffer_node->read_cnt)
	{
		if (buffer_node->buffer[idx] == '\n')
			return (idx);
		idx++;
	}
	if (buffer_node->read_cnt < BUFFER_SIZE)
		return (buffer_node->read_cnt - 1);
	return (-1);
}


/*
This function returns fd matching head pointer. If there are no match, it add 
head pointing node to the end of the list and returns it. 
*/
t_h_p_node	*search_fd_matching_head_ptr(int fd, t_h_p_node *head_ptr_arr)
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


/*
This function returns character count from starting point to end point. 
*/
size_t	count_char_till_end(t_h_p_node	*head_ptr)
{
	t_b_node	*b_node;
	size_t		count;

	b_node = head_ptr->head;
	count = 0;
	while (TRUE)
	{
		if (b_node->end == -1)
		{
			count += BUFFER_SIZE - b_node->start;
			b_node->next = make_new_b_node(head_ptr->fd);
			if (b_node->next == NULL)
				return (count);
			b_node = b_node->next;
		}
		else
		{
			count += b_node->end - b_node->start + 1;
			return (count);
		}
	}
}


/*
This function copies characters from buffer to mallocated string. Nul 
turmination needed at the end of string.
*/
void copy_char_from_buffer_to_str(t_h_p_node *head_ptr, char *str)
{
	t_b_node	*b_node;
	size_t		copy_size;

	b_node = head_ptr->head;
	while (TRUE)
	{
		if (b_node->end == -1)
		{
			copy_size = BUFFER_SIZE - b_node->start;
			ft_memcpy(str, b_node->buffer + b_node->start, copy_size);
			str += copy_size;
			b_node->next = make_new_b_node(head_ptr->fd);
			if (b_node->next == NULL)
				return (str);
			head_ptr->head = b_node->next;
		}
		else // end exist in this buffer
		{
			copy_size = b_node->end - b_node->start + 1;
			ft_memcpy(str, b_node->buffer + b_node->start, copy_size);

		}
	}
	

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







