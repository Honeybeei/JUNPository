/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stylized_arg_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:22:04 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/22 22:33:43 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Detect format specification, translate it and get format-matching stylized
// string which is the result of 'fmt_spec + optional argument'. It returns the 
// array of stylized strings.
char	**get_stylized_arg_list(char *str, va_list ap)
{
	char	**stylized_arg_list;
	int		i;

	stylized_arg_list = malloc(sizeof(char *) * (count_fmt_spec(str) + 1));
	if (stylized_arg_list == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str = arg_to_str(str, stylized_arg_list[i], ap);
			i++;
		}
		else
			str++;
	}
	return (stylized_arg_list);
}

// Count format specifications and return its number
int	count_fmt_spec(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}

// Read format specification starting from *str. Returns the string which is the
// result of applying format specification to an optional argument. Return the 
// location of the char after format specification. 
char *arg_to_str(char *str, char *dst, va_list ap)
{
	t_fmt_spec fmt_spec;

	str = read_fmt_spec(str, ap, &fmt_spec);
	dst = apply_fmt_spec(fmt_spec, ap);  // TODO
	return (str);
}
