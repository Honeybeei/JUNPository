/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:01:32 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/07 21:48:11 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define BUFFER_SIZE 15  // will be compiled with -D option. now just for making

typedef struct s_buf
{
	char			buf[BUFFER_SIZE + 1];
	bool			eof;
	struct s_buf	*next;
}	t_buf;

typedef struct s_head_list
{
	int					fd;
	t_buf				*head_node;
	struct s_head_list	*next;
}	t_head_list;

// get_next_line.c
char		*get_next_line(int fd);
t_head_list	*search_matching_fd(int fd, t_head_list *head_node_list);
t_buf		*new_buf_node(int fd);
char		*termination_protocol(t_head_list *head_p);
size_t		count_char(t_buf *buf_p);
void		copy_data_from_buf_to_str(t_buf *buf_p, char *str);

// get_next_line_utils.c
void		*ft_memchr(const void *s, int c, size_t n);

#endif