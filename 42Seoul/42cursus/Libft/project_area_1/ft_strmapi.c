/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:44:09 by seoyoo            #+#    #+#             */
/*   Updated: 2022/05/04 15:30:05 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	str_len;
	char	*new_str;
	size_t	i;

	str_len = ft_strlen(s);
	new_str = malloc((str_len + 1) * sizeof(char));
	i = 0;
	while (i < str_len)
	{
		new_str[i] = f((unsigned int)i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
