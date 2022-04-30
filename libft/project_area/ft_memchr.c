/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:41:07 by seoyoo            #+#    #+#             */
/*   Updated: 2022/04/30 02:36:04 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*temp;

	c = (char)c;
	temp = (char *)s;
	if (n == 0)
		return (NULL);
	while (n > 0)
	{
		if (*temp == c)
			return (temp);
		temp++;
		n--;
	}
	return (NULL);
}
