/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:55:15 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/09 17:04:19 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_test_utils.h"

void    print_buffer_node_info(t_b_node *node)
{
	printf("Address : %p\nread count : %zd\n", node, node->read_count);
	printf("start idx : %ld\n", node->start - node->buffer);
	if (node->end == NULL)
		printf("end idx   : NULL\n");
	else
		printf("end idx   : %ld\n", node->end - node->buffer);
	for (size_t i = 0; i < BUFFER_SIZE; i++)
	{
		if (node->buffer[i] == '\n')
			printf("[%4s]", "\\n");
		else if (node->buffer[i] == 0)
			printf("[%4s]", "\\0");
		else
			printf("[%4c]", node->buffer[i]);
	}
	printf("\n\n");
}

/*
Fuction to test if new_buf_node() works perfectly. 
Yeah it seems working :)
*/
void	print_node_to_eof(t_h_ptr *head_ptr)
{
	t_b_node	*head;

	head = head_ptr->head;
	while (TRUE)
	{
		if (head == NULL)
		{
			printf("\nEOF\n");
			return;
		}
		else
        {
			print_buffer_node_info(head);
			head->next = new_buf_node(head_ptr->fd);
            head = head->next;
        }
	}
}
