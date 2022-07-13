/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test_utils.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:47:55 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/11 22:51:20 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_TEST_UTILS_H
# define GET_NEXT_LINE_TEST_UTILS_H

# include "get_next_line.h"
# include <stdio.h>

void    print_buffer_node_info(t_b_node *node);
void    print_all_buffers(int fd);

#endif