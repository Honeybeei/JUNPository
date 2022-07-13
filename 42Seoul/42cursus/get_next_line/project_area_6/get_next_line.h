/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:51:34 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/13 00:04:58 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>  // malloc(), free()
#include <unistd.h>  // open()

# define BUFFER_SIZE 2
# define TRUE 1
# define FALSE 0

/*
If there are no ending point at current buffer, end will be set to -1
*/
typedef struct s_buffer_node
{
	char 					buffer[BUFFER_SIZE];
	ssize_t					start;
	ssize_t					end;
	ssize_t					read_cnt;
	struct s_buffer_node	*next;
}	t_b_node;

typedef struct s_head_pointer_node
{
	int							fd;
	t_b_node					*head;
	struct s_head_pointer_node	*next;
}	t_h_p_node;

// get_next_line.c
char		*get_next_line(int fd);
t_h_p_node	*make_new_h_p_node(int fd);
t_b_node	*make_new_b_node(int fd);
ssize_t 	find_closest_end(t_b_node *buffer_node);



#endif