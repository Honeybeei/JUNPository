/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:57:48 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/06 23:20:04 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
This function reads data from fd and save it to t_buf->buf and points first
occured next line sign('\n') or EOF. returns NULL when reading error
*/
t_buf	*make_new_buff_n_read(int fd)
{
	t_buf	*new_buf;

	new_buf = malloc(sizeof(t_buf));
	if (new_buf == NULL)
		return (NULL);
	new_buf->start_p = new_buf->buf;
	new_buf->read_cnt = read(fd, new_buf->buf, BUFFER_SIZE);
	new_buf->next = NULL;
	if (new_buf->read_cnt == -1)
	{
		free(new_buf);
		return (NULL);
	}
	return (new_buf);
}

/*
terminate buffer nodes. when reading process is stopped by occurence of new line
, leave the last buffer node. If EOF stopped reading, erase every buffer node. 
*/
void	termination_protocol(t_head_list *head_p, bool end_type)
{
	t_buf	*del_node;

	while (head_p->head_node->next != NULL)
	{
		del_node = head_p->head_node;
		head_p->head_node = head_p->head_node->next;
		free(del_node);
	}
	if (end_type == EOF_END)
		free(head_p->head_node);
}

/*
This function counts number of character from head->start_p to end.
*/
size_t	count_char_in_buff(t_buf *head, char *end)
{
	char	*char_p;
	size_t	n;

	n = 0;
	char_p = head->start_p;
	while (char_p != end)
	{
		n++;
		if (char_p == head->buf + (BUFFER_SIZE - 1))
		{
			head = head->next;
			char_p = head->start_p;
		}
		else
			char_p++;
	}
	return (n);
}

/*
this function copies char from buff to str.
WARNING : it doesnt copy the end char such as '\n' or '\0' in this project.
*/
void	copy_from_buf_to_str(t_buf *head, char *end, char *str)
{
	char	*char_p;

	char_p = head->start_p;
	while (char_p != end)
	{
		*str = *char_p;
		if (char_p == head->buf + (BUFFER_SIZE - 1))
		{
			head = head->next;
			char_p = head->start_p;
		}
		else
			char_p++;
		str++;
	}
}
