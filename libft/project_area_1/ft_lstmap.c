/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:19:47 by seoyoo            #+#    #+#             */
/*   Updated: 2022/05/08 15:53:45 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp_src;
	t_list	*dst;
	t_list 	*temp_dst;
	t_list	*new_node;

	temp_src = lst;
	dst = NULL;
	temp_dst = dst;
	while (temp_src != NULL)
	{
		new_node = malloc(sizeof(t_list));
		temp_dst->next = new_node;
		if (new_node == NULL)
		{
			ft_lstclear(&dst, del);
			return (NULL);
		}
		new_node->content = f(temp_src->content);
		new_node->next = NULL;
		temp_dst = temp_dst->next;
		temp_src = temp_src->next;
	}
	return (dst);
}