/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:31:02 by seoyoo            #+#    #+#             */
/*   Updated: 2022/05/08 15:07:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*del_node;
	t_list	*node_p;

	if (*lst == NULL)
		return ;
	del_node = *lst;
	node_p = *lst;
	while (node_p != NULL)
	{
		node_p = node_p->next;
		del(del_node->content);
		free(del_node);
		del_node = node_p;
	}
}
