/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 05:53:02 by seoyoo            #+#    #+#             */
/*   Updated: 2022/05/01 17:39:35 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t count_strings(char *src, char c)
{
	size_t	idx_src;
	size_t	count;

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

// 'split_n_duplicate' is a function which splits string by divider
// [Parameters]
// 1. char *src : Address of src string. Will jump all the divider if they are infront of the string which we want to duplicate. 
// 2. char *dest : String which is splitted and duplicated will be pointed by this.
// 3. char divider : character which will act as divider
// [Return value]
// char * : Return NULL if dest is the last string, if not, return the src which will be splitted again.
static char	*split_n_duplicate(char *src, char *dest, char divider)
{
	size_t	str_len;
	size_t	idx;

	while (*src == divider)
		src++;
	str_len = 0;
	while (src[str_len] != divider || src[str_len] != '\0')
		str_len++;
	dest = malloc(sizeof(char) * str_len);
	if (dest == NULL)
		return NULL;
	idx = 0;
	while (idx < str_len)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	if (src[str_len] == divider)
		return (src + str_len);
	return (NULL);
}

// ft_split is a function which splits string with divider and returns the array of strings splitted.
// [Parameters]
// 1. char const *s : String which will be divided
// 2. char c : A single character which will work as a divider
// [Return value]
// char ** : Array of strings. Each string will be dynamically allocated. 
char	**ft_split(char const *s, char c)
{
	size_t	str_count;
	char	*str_arr;
	size_t	idx_str_arr;
	char	*src;

	str_count = count_strs(s, c);
	str_arr = malloc(sizeof(char *) * (str_count + 1));
	if (str_arr == NULL)
		reuturn (NULL);
	str_arr[str_count] == NULL;
	idx_str_arr = 0;
	src = (char *)s;
	while (idx_str_arr < str_count && src != NULL)
	{
		src = split_n_duplicate(src, str_arr[idx_str_arr], c);
		idx_str_arr++;
	}
	str_arr[idx_str_arr] = NULL;
	return (str_arr);
}
