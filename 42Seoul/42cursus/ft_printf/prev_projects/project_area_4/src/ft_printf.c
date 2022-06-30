/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:51:11 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/26 19:55:14 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
current status : making format s[ecification validate check functions.


*/




#include "ft_printf.h"

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
	head = read_str(ap, str);  // TODO : on going in this file
	if (head == NULL)
		return (ERROR);
	char_cnt = print_str(head);
	termination_protocol(ap, head);
	return (char_cnt);
}

void termination_protocol(va_list ap, t_fmt **head)
{
	t_fmt	*del_node;

	va_end(ap);
	while (*head != NULL)
	{
		del_node = *head;
		*head = (*head)->next;
		if (del_node->spec != NULL)
			free(del_node->spec);
		if (del_node->str != NULL)
			free(del_node->str);
		free(del_node);
	}
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
			str = read_fmt_spec(str, ap, new_node);
			if (str == NULL || !check_fmt_spec_vld(new_node->spec))  // TODO : on process in check_fmt_spec_vld.c
			{
				termination_protocol(ap, head);
				ft_putstr_fd("ERROR : INVALID FORMAT SPECIFICATION\n", 1);
				break;
			}
			stylize_arg_to_str(ap, new_node);  // TODO : on process in this file
		}
		else
			str = read_plain_str(str, new_node);  // TODO
	}
	return (head);  // if *head == NULL -> it is error
}

// stylize_arg_to_str.c
stylize_arg_to_str(va_list ap, t_fmt *new_node)
{
	if (new_node->spec->type == '%')
		stylize_percent_type_arg(new_node);
	else if (new_node->spec->type == 'c')
		stylize_char_type_arg(ap, new_node);
	else if (new_node->spec->type == 's')
		stylize_str_type_arg(ap, new_node);
	else if (new_node->spec->type == 'p')
		stylize_ptr_type_arg(ap, new_node);
	else if (new_node->spec->type == 'd' || new_node->spec->type == 'i')
		stylize_int10_type_arg(ap, new_node);
	else if (new_node->spec->type == 'u')
		stylize_unsigned_int10_type_arg(ap, new_node);
	else if (new_node->spec->type == 'x' || new_node->spec->type == 'X')
		stylize_int16_type_arg(ap, new_node, new_node->spec->type);
}

stylize_percent_type_arg(t_fmt *fmt_node)
{
	
}

stylize_char_type_arg(va_list ap, t_fmt *fmt_node)
{
	
}
