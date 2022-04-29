/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:51:13 by seoyoo            #+#    #+#             */
/*   Updated: 2022/04/28 20:23:39 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (0 < dstsize && dst_len < dstsize)
	{
		i = 0;
		while (i < src_len && i + dst_len < dstsize - 1)
		{
			dst[i + dst_len] = src[i];
			i++;
		}
		dst[i + dst_len] = 0;
	}
	else
		dst_len = dstsize;
	return (dst_len + src_len);
}
