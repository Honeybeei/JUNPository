/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:55:57 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/06 23:19:08 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_head_list	*head_node_list = NULL;
	t_head_list			*head_p;
	t_buf				*head;
	t_buf				*tail;
	char				*new_line_p;

	head_p = search_matching_fd(fd, head_node_list);
	head = head_p->head_node;
	tail = head;
	while (true)
	{
		new_line_p = search_for_new_line(tail);
		if (new_line_p != NULL)
		{
			return (new_line_end(head_p, new_line_p, tail));
		}
		else if (tail->read_cnt < BUFFER_SIZE)
			return (eof_end(head_p, tail));
		else
		{
			tail->next = make_new_buff_n_read(fd);
			tail = tail->next;
		}
	}
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
		if (head_node_list->fd == fd)
			return (head_node_list);
		else
		{
			if (head_node_list->next == NULL)
			{
				head_node_list->next = malloc(sizeof(t_head_list));
				if (head_node_list->next == NULL)
					return (NULL);
				head_node_list->next->fd = fd;
				head_node_list->next->head_node = make_new_buff_n_read(fd);
				head_node_list->next->next = NULL;
				return (head_node_list->next);
			}
			else
				head_node_list = head_node_list->next;
		}
	}
}

/*
This function search '\n' from the start_p in buf and returns first occured '\n'
address. NULL will be returned if '\n' is not found. 
*/
char	*search_for_new_line(t_buf *buf)
{
	size_t	search_range;

	search_range = buf->read_cnt - (buf->start_p - buf->buf);
	return (ft_memchr(buf->start_p, '\n', search_range));
}

/*
returns completed string when get next line process stops at new line
*/
char	*new_line_end(t_head_list *head_p, char *new_line_p, t_buf *tail)
{
	char	*str;
	size_t	str_buf_size;

	if (new_line_p - tail->buf == BUFFER_SIZE - 1)
	{
		tail->next = make_new_buff_n_read(head_p->fd);
		tail = tail->next;
	}
	str_buf_size = count_char_in_buff(head_p->head_node, new_line_p) + 2;
	str = malloc(sizeof(char) * (str_buf_size));
	copy_from_buf_to_str(head_p->head_node, new_line_p, str);
	str[str_buf_size - 2] = '\n';
	str[str_buf_size - 1] = '\0';
	termination_protocol(head_p, NEW_LINE_END);
	return (str);
}

/*
returns completed string when get next line process stops at new line
*/
char	*eof_end(t_head_list *head_p, t_buf *tail)
{
	char	*end_p;
	char	*str;
	size_t	str_buf_size;

	end_p = tail->buf + (tail->read_cnt - 1);
	str_buf_size = count_char_in_buff(head_p->head_node, end_p) + 2;
	str = malloc(sizeof(char) * (str_buf_size));
	copy_from_buf_to_str(head_p->head_node, end_p, str);
	str[str_buf_size - 2] = *end_p;
	str[str_buf_size - 1] = '\0';
	termination_protocol(head_p, EOF_END);
	return (str);
}
