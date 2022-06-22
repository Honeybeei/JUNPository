/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 02:30:53 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/21 17:20:32 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// < abbreviation guide >
// argument = arg
// pointer = ptr
// format = fmt
// specification = spec
// print = pnt
// count = cnt
// string = str
// source = src
// destination = dst

// Discription
// `printf` is a function which takes a string and optional arguments and prints
// a formatted sequence of characters. Finally it returns the number of charac-
// ters that are printed.

// Arguments
// First argument should be the address of the formatted string.
// Following optional argument will be pointed by arg_ptr and will be printed at
// the location of its placeholder while first argument is printed.

// Return values
// Simple. It returns the number of the printed characters.

int ft_printf(const char *format, ...)
{
	va_list arg_ptr;
	char *str;
	int printed_char_cnt;
	t_fmt_spec fmt_spec;

	printed_char_cnt = 0;
	str = (char *)format;
	va_start(arg_ptr, format);
	while (str)
	{
		if (*str == '%')
		{
			str = read_fmt_spec(str, arg_ptr, &fmt_spec);
			// fmt_spec_validity_check(&fmt_spec); TODO
			printed_char_cnt += print_fmt_spec(&fmt_spec, arg_ptr);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			printed_char_cnt++;
			str++;
		}
	}
	return (printed_char_cnt);
}

int	print_fmt_spec(t_fmt_spec *fmt_spec, va_list arg_ptr)
{
	t_fmt_str fmt_str;

	fmt_str.pre_fmt_str = read_arg(fmt_spec, arg_ptr);

	if (fmt_str.pre_fmt_str != NULL)
		free(fmt_str.pre_fmt_str);
	if (fmt_str.formatted_str != NULL)
		free(fmt_str.formatted_str);
}

char	*read_arg(t_fmt_spec *fmt_spec, va_list arg_ptr)
{
	t_fmt_str	fmt_str;

	initialize_fmt_str(&fmt_str);
	if (fmt_spec->type == 'c')
		read_arg_c(arg_ptr, &fmt_str);
	else if (fmt_spec->type == 's')
		read_arg_s(arg_ptr, &fmt_str);
	else if (fmt_spec->type == 'p')
		read_arg_p(arg_ptr, &fmt_str);
	else if (fmt_spec->type == 'd' || fmt_spec->type == 'i')
		read_arg_di(arg_ptr, &fmt_str);
	else if (fmt_spec->type == 'u')
		read_arg_u(arg_ptr, &fmt_str);
	else if (fmt_spec->type == 'x' || fmt_spec->type == 'X')
		read_arg_xX(arg_ptr, &fmt_str);
	else if (fmt_spec->type == '%')
		read_arg_percentage(fmt_spec, arg_ptr, &fmt_str);
}

void initialize_fmt_str(t_fmt_str *fmt_str)
{
	fmt_str->pre_fmt_str =  NULL;
	fmt_str->formatted_str = NULL;
	fmt_str->right_align = true;
	fmt_str->min_width = 0;
	fmt_str->padding_char = ' ';
	fmt_str->plus_sign = '\0';
}

void read_arg_c(va_list arg_ptr, t_fmt_str *fmt_str)
{
	fmt_str->pre_fmt_str = malloc(sizeof(char) * 2);
	fmt_str->pre_fmt_str[0] = va_arg(arg_ptr, char);
	fmt_str->pre_fmt_str[1] = '\0';
}

void read_arg_s(va_list arg_ptr, t_fmt_str *fmt_str)
{
	fmt_str->pre_fmt_str = va_arg(arg_ptr, char *);
}

void read_arg_p(va_list arg_ptr, t_fmt_str *fmt_str)
{
	long long address;

	address = va_arg(arg_ptr, void *);
	
}

