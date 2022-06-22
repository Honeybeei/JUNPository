/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fmt_spec0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:04:13 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/22 22:33:55 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Read format specification and save specifications to fmt_spec.
char *read_fmt_spec(char *str, va_list ap, t_fmt_spec *fmt_spec)
{
	initialize_fmt_spec(fmt_spec);
	str = read_flag(str, fmt_spec);
	str = read_width(str, fmt_spec, ap);
	str = read_precision(str, fmt_spec, ap);
	str = read_size(str, fmt_spec);
	str = read_type(str, fmt_spec);
	return (str);
}

// Initialize format specification variable
void	initialize_fmt_spec(t_fmt_spec *fmt_spec)
{
	initialize_flag(&(fmt_spec->flag));
	fmt_spec->specified_width = 0;
	fmt_spec->precision = 0;
	ft_bzero(fmt_spec->precision, 3);
	fmt_spec->type = 0;
}

// Initialize flag variable
void	initialize_flag(t_flag *flag)
{
	flag->minus = false;
	flag->plus = false;
	flag->zero = false;
	flag->space = false;
	flag->hash = false;
}

// Read flag specification
char	*read_flag(char *str, t_fmt_spec *fmt_spec)
{
	str++;
	while (switch_flag(*str, fmt_spec->flag))
		str++;
	return (str);
}

// Change properties of flag variable
int	switch_flag(char c, t_flag flag)
{
	if (c == '-')
		flag.minus = true;
	else if (c == '+')
		flag.plus = true;
	else if (c == '0')
		flag.zero = true;
	else if (c == ' ')
		flag.space = true;
	else if (c == '#')
		flag.hash = true;
	else
		return (0);
	return (1);
}
