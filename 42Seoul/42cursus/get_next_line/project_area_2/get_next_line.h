/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:01:32 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/06 23:17:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define BUFFER_SIZE 10  // will be compiled with -D option. now just for making
# define NEW_LINE_END 1
# define EOF_END 0

typedef struct s_buf
{
	char			buf[BUFFER_SIZE];
	char			*start_p;
	ssize_t			read_cnt;
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
char		*search_for_new_line(t_buf *buf);
char		*new_line_end(t_head_list *head_p, char *new_line_p, t_buf *tail);
char		*eof_end(t_head_list *head_p, t_buf *tail);

// get_next_line_utils.c
void		*ft_memchr(const void *s, int c, size_t n);
t_buf		*make_new_buff_n_read(int fd);
void		termination_protocol(t_head_list *head_p, bool end_type);
size_t		count_char_in_buff(t_buf *head, char *end);
void		copy_from_buf_to_str(t_buf *head, char *end, char *str);

#endif