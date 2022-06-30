/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fmt_spec_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:32:34 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/26 16:05:57 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*read_width(char *str, t_spec *spec, va_list ap)
{
	if (*str == '*')
	{
		spec->specified_width = va_arg(ap, int);
		str++;
	}
	else
	{
		while ('0' <= *str && *str <= '9')
		{
			spec->specified_width *= 10;
			spec->specified_width += *str - '0';
			str++;
		}
	}
	return (str);
}

char	*read_precision(char *str, t_spec *spec, va_list ap)
{
	if (*str == '.')
	{
		str++;
		if (*str == '*')
		{
			spec->precision = va_arg(ap, int);
			str++;
		}
		else
		{
			while ('0' <= *str && *str <= '9')
			{
				spec->precision *= 10;
				spec->precision += *str - '0';
				str++;
			}
		}
	}
	return (str);
}

char	*read_size(char *str, t_spec *spec)
{
	int	i;

	i = 0;
	while (!is_type_spec(*str))
	{
		if (i > SIZE_SPEC_BUFF)
		{
			ft_bzero(spec->size, SIZE_SPEC_BUFF);
			return (str);
		}
		spec->size[i] = *str;
		i++;
		str++;
	}
	return (str);
}

char	*read_type(char *str, t_spec *spec)
{
	spec->type = is_type_spec(*str);
	str++;
	return (str);
}