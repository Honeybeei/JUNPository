/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:51:11 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/28 22:25:13 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ver4.0 -> ver4.1 changed : chaged t_fmt->spec
added size and type specification and it will be treated together as a string. 
*/

#include "../inc/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_fmt	**head;
	int		char_cnt;
	char	*str;

	va_start(ap, format);
	str = (char *)format;
	if (*str == '\0')
		return (0);
	head = read_str(ap, str);
	if (head == NULL)
		return (ERROR);
	char_cnt = print_str(head);
	termination_protocol(ap, head);
	return (char_cnt);
}

void termination_protocol(va_list ap, t_fmt **head)
{
	va_end(ap);
	terminate_t_fmt_list(head);
}

t_fmt	**read_str(va_list ap, char *str)
{
	t_fmt	**head;
	t_fmt	**tail;
	t_fmt	*new_node;

	head = NULL;
	tail = head;
	while (*str)
	{
		new_node = new_t_fmt_node(tail);
		if (head == NULL)
			*head = new_node;
		if (*str == '%')
		{
			str = read_format(str, ap, new_node);
			if (str == NULL)
				return (NULL);
		}
		else
			str = read_plain_str(str, new_node);  // TODO
	}
	return (head);
}

