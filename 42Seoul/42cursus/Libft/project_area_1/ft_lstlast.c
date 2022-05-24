/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 00:02:39 by seoyoo            #+#    #+#             */
/*   Updated: 2022/05/06 08:40:56 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node_p;

	node_p = lst;
	if (node_p == NULL)
		return (node_p);
	while (node_p->next != NULL)
		node_p = node_p->next;
	return (node_p);
}
