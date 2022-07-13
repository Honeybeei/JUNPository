/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:45:49 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/11 22:51:38 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_test_utils.h"

// Functions for testing
void	print_buffer_node_info(t_b_node *node)
{
	printf("Node buffer address : %p\n", node->buffer);
	printf("Start : %ld\n", node->start - node->buffer);
	if (node->end == NULL)
		printf("END   : NULL\n");
	else
		printf("END  : %ld\n", node->end - node->buffer);
	printf("Read count : %zd\n", node->read_cnt);
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (node->buffer[i] == '\n')
			printf("[\\n ]");
		else if (node->buffer[i] == '\0')
			printf("[\\0 ]");
		else
			printf("[ %c ]", node->buffer[i]);
	}
	printf("\n\n");
}

void	print_all_buffers(int fd)
{
	t_b_node    *new_node;

	while (TRUE)
	{
		new_node = make_new_node(fd);
		if (new_node == NULL)
			break;
		else
			print_buffer_node_info(new_node);
	}
}
