/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fmt_spec2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:47:50 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/20 14:41:31 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*read_width(char *str, t_fmt_spec *fmt_spec, va_list arg_ptr)
{
	if (*str == '*')
	{
		fmt_spec->specified_width = va_arg(arg_ptr, int);
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

char	*read_precision(char *str, t_fmt_spec *fmt_spec, va_list arg_ptr)
{
	if (*str == '.')
	{
		str++;
		if (*str == '*')
		{
			fmt_spec->precision = va_arg(arg_ptr, int);
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

char	*read_size(char *str, t_fmt_spec *fmt_spec)
{
	int	i;

	i = 0;
	while (!is_type_spec(str))
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

char	*read_type(char *str, t_fmt_spec *fmt_spec)
{
	fmt_spec->type = is_type_spec(*str);
	str++;
	return (str);
}

char	is_type_spec(char c)
{
	char	*type_list;
	int		i;
	int		type_count;

	type_list = "cspdiuxX%";
	type_count = ft_strlen(type_list);
	i = 0;
	while (i < type_count)
	{
		if (type_list[i] == c)
			return (c);
		i++;
	}
	return (0);
}