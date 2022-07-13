/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:42:25 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/12 17:41:40 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>  // malloc(), free()
#include <unistd.h>  // open()

# define BUFFER_SIZE 1
# define TRUE 1
# define FALSE 0

typedef struct s_buffer_node
{
	char buffer[BUFFER_SIZE];
	char					*start;
	char					*end;
	ssize_t					read_cnt;
	struct s_buffer_node	*next;
}	t_b_node;

typedef struct s_head_pointer_node
{
	int							fd;
	t_b_node					*head;
	struct s_head_pointer_node	*next;
}	t_h_p_node;

char		*get_next_line(int fd);
t_h_p_node  *search_fd_matching_head_ptr(int fd, t_h_p_node *head_ptr_arr);
t_h_p_node	*make_new_h_p_node(int fd);
t_b_node	*make_new_node(int fd);
size_t		count_char_till_end(t_h_p_node *head_ptr);
void		*ft_memchr(const void *s, int c, size_t n);
void		copy_char_from_buffer_to_str(t_h_p_node *head_ptr, char *str);
void		termination_protocol(t_h_p_node *head_ptr);




#endif