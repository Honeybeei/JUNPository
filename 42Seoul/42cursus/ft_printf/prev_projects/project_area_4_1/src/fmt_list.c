/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:49:10 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/28 17:47:42 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_fmt	*new_t_fmt_node(t_fmt **tail)
{
	t_fmt	*new_node;

	new_node = malloc(sizeof(t_fmt));
	if (new_node == NULL)
		return (NULL);
	(*tail)->next = new_node;
	*tail = new_node;
	new_node->spec = NULL;
	new_node->str = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	terminate_t_fmt_list(t_fmt **head)
{
	t_fmt	*del_node;

	while (*head != NULL)
	{
		del_node = *head;
		*head = (*head)->next;
		if (del_node->spec->size_n_type != NULL)
			free(del_node->spec->size_n_type);
		if (del_node->spec != NULL)
			free(del_node->spec);
		if (del_node->str != NULL)
			free(del_node->str);
		free(del_node);
	}
}