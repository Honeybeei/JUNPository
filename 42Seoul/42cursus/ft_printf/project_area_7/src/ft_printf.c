/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:43:39 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/14 14:35:14 by seoyoo           ###   ########.fr       */
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

/*
This function parses format string and split it in to t_fmt node linked list. 
*/
t_fmt	*parse_string_to_list(char *str, va_list ap)
{
	size_t	i;
	t_fmt	*head;

	head = NULL;
	i = 0;
	while (TRUE)
	{
		if (str[i] == '%')
		{
			
		}
		else if (str[i] == '\0')
		{

		}
		else
		{
			i++;
		}
	}
	
}



int	print_format_node(t_fmt *head)
{

}



void	*termination_protocol(t_fmt *head)
{

}





