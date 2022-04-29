/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:41:07 by seoyoo            #+#    #+#             */
/*   Updated: 2022/04/28 22:47:38 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*temp;

	temp = (char *)s;
	c = (unsigned char)c;
	while (*temp != '\0' || n > 0)
	{
		if (*temp == c)
			return (temp);
		temp++;
		n--;
	}
	if (*temp == c && n > 0)
		return (temp);
	return (NULL);
}
