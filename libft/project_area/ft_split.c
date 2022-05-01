/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 05:53:02 by seoyoo            #+#    #+#             */
/*   Updated: 2022/05/01 16:26:36 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "libft.h"

size_t	count_string(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (count);
}

size_t	get_splitted_str_len(char *start, char c)
{
	size_t	i;

	i = 0;
	while (start[i] != c && start[i] != '\0')
		i++;
	return (i);
}

void	dup_split_str(char *dst, char *src, size_t str_len)
{
	dst = malloc((str_len + 1) * sizeof(char));
	if (dst == NULL)
		return ;
	ft_strlcpy(dst, src, str_len + 1);
}

char	**split_that_shit(char const *s, char c, char **str_arr)
{
	size_t	i;
	char	*temp_s;

	i = 0;
	temp_s = (char *)s;
	while (*temp_s != '\0')
	{
		if (*temp_s != c)
		{
			dup_split_str(temp_s, str_arr[i], get_splitted_str_len(temp_s, c));
			i++;
			while (*temp_s != c)
			{
				temp_s++;
				if (*temp_s == '\0')
					return (str_arr);
			}
		}
		temp_s++;
	}
	return (str_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	size_t	string_count;

	string_count = count_string(s, c);
	str_arr = malloc((string_count + 1) * sizeof(char *));
	if (str_arr == NULL)
		return (NULL);
	str_arr[string_count] = NULL;
	return (split_that_shit(s, c, str_arr));
}
*/

#include "libft.h"

size_t str_count(char *src, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] != c)
		{
			count++;
			while (src[i] != c)
			{
				if (src[i] == '\0')
					return (count);
				i++;
			}
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{

	
}

#include <stdio.h>

int main(void)
{
	char src[] = "00000";
	char divider = '0';
	printf("%lu\n", str_count(src, divider));

	return 0;
}