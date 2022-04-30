/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 05:53:02 by seoyoo            #+#    #+#             */
/*   Updated: 2022/04/30 12:22:18 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_string(char const *s, char c)
{
	size_t	i;
	size_t	flag;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			flag++;
		else
		{
			if (flag > 0)
				count++;
			flag = 0;
		}
		i++;
		if (s[i] == '\0' && flag > 0)
			count++;
	}
	return (count);
}


char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	size_t	string_count;

	string_count = count_string(s, c);
	str_arr = malloc((string_count + 1) * sizeof(char *));
	if (str_arr == NULL)
		return (NULL);
	str_arr[string_count] == NULL;
	return (str_arr);
}

#include <stdio.h>

int main(void)
{
	char str[] = "1111";
	char c = 'o';

	printf("%lu\n", count_string(str, c));
}