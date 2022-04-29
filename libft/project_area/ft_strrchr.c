/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:24:53 by seoyoo            #+#    #+#             */
/*   Updated: 2022/04/28 21:30:41 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	*temp_follower;

	c = (char)c;
	temp = (char *)s;
	temp_follower = NULL;
	while (*temp != '\0')
	{
		if (*temp == c)
			temp_follower = temp;
		temp++;
	}
	if (*temp == c)
		temp_follower = temp;
	return (temp_follower);
}
