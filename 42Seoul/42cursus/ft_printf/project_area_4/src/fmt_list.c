/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:49:10 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/25 20:12:07 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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