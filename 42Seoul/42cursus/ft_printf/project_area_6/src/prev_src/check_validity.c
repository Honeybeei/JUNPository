/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:15:27 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/28 17:20:48 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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
	if (!is_size_n_type(str))
		return (0);
	return (1);
}
