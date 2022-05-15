/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:20:49 by seoyoo            #+#    #+#             */
/*   Updated: 2022/05/09 16:31:58 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*rev_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (n > 0)
	{
		n--;
		dst_ptr[n] = src_ptr[n];
		if (n == 0)
			break ;
	}
	return (dst); 
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
		rev_memcpy(dst, src, len);
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return (dst);
}
