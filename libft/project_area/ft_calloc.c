/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:57:44 by seoyoo            #+#    #+#             */
/*   Updated: 2022/04/29 14:33:27 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*dst;
	size_t			total_size;

	total_size = count * size;
	dst = malloc(total_size);
	if (dst == NULL)
		return (NULL);
	ft_bzero(dst, total_size);
	return (dst);
}
