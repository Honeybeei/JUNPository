/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:59:21 by seoyoo            #+#    #+#             */
/*   Updated: 2022/05/08 19:47:40 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)(haystack));
	i = 0;
	while (1)
	{
		if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
			return ((char *)(&haystack[i]));
		i++;
		if (!(i + needle_len <= len))
			break ;
	}
	return (NULL);
}
