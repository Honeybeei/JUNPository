/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:23:47 by seoyoo            #+#    #+#             */
/*   Updated: 2022/05/07 15:54:12 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_strings(char const *src, char c)
{
	size_t	idx_src;
	size_t	count;

	if (src == NULL)
		return (0);
	count = 0;
	idx_src = 0;
	while (src[idx_src] != '\0')
	{
		if (src[idx_src] != c)
		{
			count++;
			while (src[idx_src] != c)
			{
				if (src[idx_src] == '\0')
					return (count);
				idx_src++;
			}
		}
		else
			idx_src++;
	}
	return (count);
}

char	**duplicate_each_str(char *src, char divider, char **str_arr)
{
	size_t str_len;
	size_t str_arr_idx;

	if (src == NULL)
		return (str_arr);
	str_arr_idx = 0;
	while (*src != '\0')
	{
		while (*src == divider)
			src++;
		str_len = 0;
		while (src[str_len] != divider && src[str_len] != '\0')
			str_len++;
		str_arr[str_arr_idx] = malloc(sizeof(char) * (str_len + 1));
		if (str_arr[str_arr_idx] == NULL)
			return (NULL);
		ft_memcpy(str_arr[str_arr_idx], src, str_len);
		str_arr[str_arr_idx][str_len] = '\0';
		str_arr_idx++;
		src += str_len + 1;
	}
	return (str_arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	str_count;
	char	**str_arr;
	char	*src_ptr;

	str_count = count_strings(s, c);
	str_arr = malloc(sizeof(char *) * (str_count + 1));
	if (str_arr == NULL)
		return (NULL);
	if (s == NULL)
		return (str_arr);
	src_ptr = (char *)s;
	duplicate_each_str(src_ptr, c, str_arr);
	str_arr[str_count] = NULL;
	return (str_arr);
}
