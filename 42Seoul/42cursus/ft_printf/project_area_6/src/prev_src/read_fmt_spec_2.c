/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fmt_spec_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:32:34 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/27 21:26:53 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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

char	*read_size_n_type(char *str, t_spec *spec)
{
	int	i;

	i = 0;
	while (!is_type_spec(str + i))
		i++;
	spec->size_n_type = malloc(sizeof(char) * (i + 2));
	if (spec->size_n_type == NULL)
		return (NULL);
	ft_memcpy(spec->size_n_type, str, i + 1);
	spec->size_n_type[i + 1] = '\0';
	return (str + i + 1);
}