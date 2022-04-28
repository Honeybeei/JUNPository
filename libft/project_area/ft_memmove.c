/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:06:48 by seoyoo            #+#    #+#             */
/*   Updated: 2022/04/28 13:13:20 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_temp;
	int		i;

	if (dst == NULL || src == NULL)
		return (dst);
	dst_temp = dst;
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			dst_temp[i] = ((char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			dst_temp[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
