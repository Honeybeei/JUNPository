/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:41:16 by seoyoo            #+#    #+#             */
/*   Updated: 2022/05/06 09:30:03 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node_p;

	node_p = *lst;
	if (new == NULL)
		return ;
	if (node_p == NULL)
	{
		node_p = new;
		return ;
	}
	while (node_p->next != NULL)
		node_p = node_p->next;
	node_p->next = new;
}
