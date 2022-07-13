/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:59:53 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/09 17:00:33 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
function from libft
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	temp_c;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	temp_c = (unsigned char)c;
	while (i < n)
	{
		if (p[i] == temp_c)
			return (p + i);
		i++;
	}
	return (NULL);
}

/*
Function from libft
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	if (src != dst)
	{
		temp_src = (unsigned char *)src;
		temp_dst = (unsigned char *)dst;
		i = 0;
		while (i < n)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}

