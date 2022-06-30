/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:24:32 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/28 22:27:05 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char *read_format(char *str, va_list ap ,t_fmt *node)
{
	str++;
	if (ft_strchr("cspdiuxX%", *str))
	{
		if (*str == 'c')
			read_charcter(ap, node);
		else if (*str == 's')
			read_string(ap, node);
		else if (*str == 'p')
			read_address(ap, node);
		else if (*str == 'd' || *str == 'i')
			read_decimal(ap, node);
		else if (*str == 'u')
			read_unsigned_decimal(ap, node);
		else if (*str == 'x')
			read_hexadecimal_lower(ap, node);
		else if (*str == 'X')
			read_hexadecimal_upper(ap, node);
		else if (*str == '%')
			read_percent_sign(node);
		return (str + 1);
	}
	else
		return (NULL);
}

char *read_character(va_list ap, t_fmt *node)
{
	char c;

	c = va_arg(ap, char);
	node->str = malloc(sizeof(char) + 2);
	if (node->str == NULL)
		return (NULL);
	node->str[0] = c;
	node->str[1] = '\0';
	return (node->str);
}

char *read_string(va_list ap, t_fmt *node)
{
	node->str = ft_strdup(va_arg(ap, char *));
	return (node->str);
}

char *read_address(va_list ap, t_fmt *node)
{
	size_t ptr_address;

	ptr_address = va_arg(ap, void *);
	node->str = my_itoa()
}