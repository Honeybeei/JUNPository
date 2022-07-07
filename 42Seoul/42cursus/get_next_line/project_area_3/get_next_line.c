/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:55:57 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/07 21:54:35 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_head_list	*head_node_list = NULL;
	t_head_list			*head_p;
	t_buf				*buf_p;
	char				*new_line_p;

	head_p = search_matching_fd(fd, head_node_list);
	if (head_p == NULL)
		return (NULL);
	buf_p = head_p->head_node;
	while (true)
	{
		new_line_p = ft_memchr(buf_p->buf, '\n', BUFFER_SIZE);
		if (new_line_p != NULL)  // '\n' appear at buffer
			break;
		else  // '\n' doesnt appear at buffer
		{
			if (buf_p->eof == true)
				break;
			else
			{
				buf_p->next = new_buf_node(fd);
				buf_p = buf_p->next;
			}
		}
	}
	return (termination_protocol(head_p));
}

/*
This function returns fd-matching head node.
If there are no fd-matching head node pointer, make new head node pointer and 
add new buffer node and point with new head node pointer and return new buffer 
node.
*/
t_head_list	*search_matching_fd(int fd, t_head_list *head_node_list)
{
	while (true)
	{
		if (head_node_list == NULL)
		{
			head_node_list = malloc(sizeof(t_head_list));
			if (head_node_list == NULL)
				return (NULL);
			head_node_list->fd = fd;
			head_node_list->head_node = new_buf_node(fd);
			head_node_list->next = NULL;
		}
		else
		{
			if (head_node_list->fd == fd)
				return (head_node_list);
			else
				head_node_list = head_node_list->next;
		}
	}
}

/*
returns new buffer node. read() function will copy data from fd to buffer. 
if EOF occurs, t_buf->eof will chanved to true. if reading error occurs, NULL
will be returned.
*/
t_buf	*new_buf_node(int fd)
{
	t_buf	*new_node;
	ssize_t	read_char_cnt;

	new_node = malloc(sizeof(t_buf));
	if (new_node == NULL)
		return (NULL);
	read_char_cnt = read(fd, new_node->buf, BUFFER_SIZE);
	if (read_char_cnt > 0)
	{
		new_node->buf[read_char_cnt] = '\0';
		new_node->next = NULL;
		if (read_char_cnt < BUFFER_SIZE)
			new_node->eof = true;
		return (new_node);
	}
	else
		return (NULL);
}

/*
1. count char from start(characters before start will be changed to zero) to end
(end also will be zeroed) -> malloc reslut string. 
2. copy char data from buffer to str. copied buffer will be zeroed.
3. free all buf_p from head except the last buf_node.
4. point the last buf_node with head_p
5. return str
*/
char	*termination_protocol(t_head_list *head_p)
{
	char	*str;
	t_buf	*del_node;

	str = malloc(sizeof(char) * (count_char(head_p->head_node) + 1));
	if (str == NULL)
		return (NULL);
	copy_data_from_buf_to_str(head_p->head_node, str);
	while (head_p->head_node->next != NULL)
	{
		del_node = head_p->head_node;
		head_p->head_node = head_p->head_node->next;
		printf("[del node : %p |]", del_node);
		free(del_node);
	}
	return (str);
}

/*
count characters between start and end('\n' or 0)
*/
size_t	count_char(t_buf *buf_p)
{
	char	*char_p;
	size_t	count;

	char_p = buf_p->buf;
	while (*char_p == 0)
		char_p++;
	count = 0;
	while (*char_p != '\n')
	{
		if (*char_p != 0)
		{
			count++;
			char_p++;
		}
		else if (buf_p->eof == true)
			return (count);
		else
		{
			buf_p = buf_p->next;
			char_p = buf_p->buf;
		}
	}
	return (count + 1);
}

/*
copy data from buffer to string between start 
*/
void	copy_data_from_buf_to_str(t_buf *buf_p, char *str)
{
	char	*char_p;

	char_p = buf_p->buf;
	while (*char_p == 0)
		char_p++;
	while (*char_p != '\n')
	{
		if (*char_p != 0)
		{
			*str = *char_p;
			*char_p = 0;
			str++;
			char_p++;
		}
		else if (buf_p->eof == true)
		{
			*str = *char_p;
			return;
		}
		else
		{
			buf_p = buf_p->next;
			char_p = buf_p->buf;
		}
	}
	str[0] = '\n';
	str[1] = 0;
}

