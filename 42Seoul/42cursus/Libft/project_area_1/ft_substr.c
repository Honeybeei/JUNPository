/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:26:11 by seoyoo            #+#    #+#             */
/*   Updated: 2022/05/10 14:56:16 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	dst = malloc((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	if (start + len <= ft_strlen(s))
		ft_strlcpy(dst, &(s[start]), len + 1);
	return (dst);
}
