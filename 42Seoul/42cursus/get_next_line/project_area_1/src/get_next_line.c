/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:55:57 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/05 21:40:31 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_str_saver	*saved_str_list = NULL;
	t_str_saver	*str_saver;
	
	str_saver = search_saved_str(fd, saved_str_list);
	if (str_saver->saved_str == NULL)
	{
		// when there is no saved string
	}
	else
	{
		// when there is saved string
	}
}


t_str_saver *search_saved_str(int fd, t_str_saver *saved_str_list)
{
	if (saved_str_list == NULL)
	{
		saved_str_list->fd = fd;
		saved_str_list->next = NULL;
		saved_str_list->saved_str = NULL;
		return (saved_str_list);
	}
	while (true)
	{
		if (saved_str_list->fd == fd)
			return (saved_str_list);
		else
		{
			if (saved_str_list->next != NULL)
				saved_str_list = saved_str_list->next;
			else
				saved_str_list->next = malloc(sizeof(t_str_saver));
				if (saved_str_list->next == NULL)
					return (NULL);
				saved_str_list->next->fd = fd;
				saved_str_list->next->next = NULL;
				saved_str_list->next->saved_str = NULL;
				return (saved_str_list->next);
		}
	}
}

t_string **split_string_at_next_line(t_string *str)
{
	size_t	i;
	t_string *splitted_str[2];

	i = 0;
	while (i < str->buf_size)
	{
		if (str->str[i] == '\n')
			break;
		i++;
	}
	splitted_str[0] = make_string(str->str, i);
	if (str->buf_size - i > 1)
	{
		i++;
		splitted_str[1] = make_string((str->str) + i, str->buf_size - i);
	}
	else
		splitted_str[1] = NULL;
	return (splitted_str);
}

t_string	*make_string(char *str, size_t buf_size)
{
	t_string	*string;

	if (buf_size == 0)
		return (NULL);
	string = malloc(sizeof(t_string));
	if (string == NULL)
		return (NULL);
	string->buf_size = buf_size;
	string->str = malloc(sizeof(char) * buf_size);
	if (string->str == NULL)
		return (NULL);
	ft_memcpy(string->str, str, buf_size);
	return (string);
}