/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fmt_spec1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:30:41 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/23 17:19:39 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

// Read width specification. If '*' occurs at width field, read ap and take it 
// as a width
char	*read_width(char *str, t_fmt_spec *fmt_spec, va_list ap)
{
	if (*str == '*')
	{
		fmt_spec->specified_width = va_arg(ap, int);
		str++;
	}
	else
	{
		while ('0' <= *str && *str <= '9')
		{
			fmt_spec->specified_width *= 10;
			fmt_spec->specified_width += *str - '0';
			str++;
		}
	}
	return (str);
}

// Read precision specification. Act same as read_width() when '*' occurs
char	*read_precision(char *str, t_fmt_spec *fmt_spec, va_list ap)
{
	if (*str == '.')
	{
		str++;
		if (*str == '*')
		{
			fmt_spec->precision = va_arg(ap, int);
			str++;
		}
		else
		{
			while ('0' <= *str && *str <= '9')
			{
				fmt_spec->precision *= 10;
				fmt_spec->precision += *str - '0';
				str++;
			}
		}
	}
	return (str);
}

// Read size specification.
char	*read_size(char *str, t_fmt_spec *fmt_spec)
{
	int	i;

	i = 0;
	while (!is_type_spec(*str))
	{
		if (i > 3)
		{
			ft_bzero(fmt_spec->size, 3);
			return (str);
		}
		fmt_spec->size[i] = *str;
		i++;
		str++;
	}
	return (str);
}

// Read type specification. 
char	*read_type(char *str, t_fmt_spec *fmt_spec)
{
	fmt_spec->type = is_type_spec(*str);
	str++;
	return (str);
}

// Return if c(parameter) is type conversion specifier character
char	is_type_spec(char c)
{
	char	*type_list;
	int		i;

	type_list = "cspdiuxX%";
	i = 0;
	while (type_list[i])
	{
		if (type_list[i] == c)
			return (c);
		i++;
	}
	return (0);
}
