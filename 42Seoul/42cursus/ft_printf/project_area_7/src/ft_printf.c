/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:43:39 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/13 21:22:28 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <errno.h>

/*
This function read format string and print to STD output. 
*/
int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	t_fmt	*head;
	int		char_count;

	va_start(ap, format);
	str = (char *)format;
	if (str == NULL || *str == '\n')
		return (0);
	head = parse_string_to_list(str, ap);
	if (head == NULL)
		return (0);
	char_count = print_format_node(head);
	termination_protocol(head);
	return (char_count);
}

t_fmt	*parse_string_to_list(char *str, va_list ap)
{
	
}

int	print_format_node(t_fmt *head)
{

}

termination_protocol(t_fmt *head)
{

}