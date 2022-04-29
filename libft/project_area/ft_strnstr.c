/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:59:21 by seoyoo            #+#    #+#             */
/*   Updated: 2022/04/29 11:55:43 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	char	*haystack_p;

	if (haystack == NULL || needle == NULL)
		return (NULL);
	haystack_p = (char *)haystack;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return (haystack_p);
	while (needle_len <= len && *haystack_p != '\0')
	{
		if (*haystack_p == *needle)
		{
			if (ft_strncmp(haystack_p, needle, needle_len) == 0)
				return (haystack_p);
		}
		len--;
		haystack_p++;
	}
	return (NULL);
}
