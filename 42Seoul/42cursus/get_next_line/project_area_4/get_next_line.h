/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:01:32 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/10 23:18:11 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>  // open()
# include <stdlib.h>  // malloc(), free()

# define BUFFER_SIZE 3  // will be compiled with -D option. now just for making
# define TRUE 1
# define FALSE 0

typedef struct s_buffer_node
{
	char					buffer[BUFFER_SIZE];
	ssize_t					read_count;
	char					*start;
	char					*end;
	struct s_buffer_node	*next;
}	t_b_node;

typedef struct s_head_node_pointer
{
	int							fd;
	t_b_node					*head;
	struct s_head_node_pointer	*next;
}	t_h_ptr;

// get_next_line.c
char		*get_next_line(int fd);
t_h_ptr 	*search_matching_fd(int fd, t_h_ptr *head_ptr_list);
t_b_node    *new_buf_node(int fd);
size_t		count_char(t_h_ptr *head_ptr);
void		copy_char_from_buf_to_str(t_h_ptr *head_ptr, char *str);
void		termination_protocol(t_h_ptr *head_ptr);
// get_next_line_utils.c
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
#endif