/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:15:27 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/26 19:56:02 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Check format specification syntax validity. It checks the specifications are 
// listed in the following order. %[flag][width][.precision][size]type
// Return 1 when they are listed in the correct order. Return 0 if not.
int check_fmt_spec_syntax_vld(char *str)
{
	str++;
	while (is_flag_spec(str))
		str++;
	while (is_num(str))
		str++;
	if(*str == '.')
	{
		str++;
		if (!is_num(str))
			return (0);
		while (is_num(str))
			str++;
	}
	str = check_size_spec_syntax_vld(str);  // TODO
	if (!is_type_spec(str))
		return (0);
	return (1);
}

check_size_spec_syntax_vld(char *str)
{
	is_single_digit_size_spec(str);

}

// Check format specification validity. Return 0 if format specification is inv-
// alid. return 1 if it is valid.
int check_fmt_spec_vld(t_spec *spec)
{
	if (!check_type_spec_vld(spec->type))  // TODO
		return (0);
	if (!check_size_vld(spec->type))  // TODO
		return (0);
	if (!check_size_type_match_vld(spec->size, spec->type))  // TODO
		return (0);
	if (!check_flag_combination_vld(spec->flag, spec->type))  // TODO
		return (0);
	return (1);
}