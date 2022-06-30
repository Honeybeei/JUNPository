/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fmt_spec_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:29:04 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/27 21:18:01 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*read_fmt_spec(char *str, va_list ap, t_fmt *new_node)
{
	if (!check_fmt_spec_syntax_vld(str));
		return (NULL);
	initialize_spec(new_node->spec);
	str = read_flag(str, new_node->spec);
	str = read_width(str, new_node->spec, ap);
	str = read_precision(str, new_node->spec, ap);
	str = read_size_n_type(str, new_node->spec);
	return (str);
}

void	initialize_fmt_spec(t_spec *spec)
{
	initialize_flag(&(spec->flag));
	spec->specified_width = 0;
	spec->precision = 0;
	spec->size_n_type = NULL;
}

void	initialize_flag(t_flag *flag)
{
	flag->minus = false;
	flag->plus = false;
	flag->zero = false;
	flag->space = false;
	flag->hash = false;
}

char	*read_flag(char *str, t_spec *spec)
{
	str++;
	while (switch_flag(*str, spec->flag))
		str++;
	return (str);
}

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