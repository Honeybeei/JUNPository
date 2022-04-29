/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:30:48 by seoyoo            #+#    #+#             */
/*   Updated: 2022/04/28 21:24:03 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp;

	c = (char)c;
	temp = (char *)s;
	while (*temp != '\0')
	{
		if (*temp == c)
			return (temp);
		temp++;
	}
	if (*temp == c)
		return (temp);
	return (NULL);
}
