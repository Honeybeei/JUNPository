/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:53:45 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/23 20:25:19 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	char	*str;
	char	**stylized_arg_list;
	va_list	ap;
	int		str_len;

	str = (char *)format;
	if (format == NULL)
		return (ERROR);
	va_start(ap, format);
	stylized_arg_list = get_stylized_arg_list(str, ap);
	replace_fmt_specs(str, stylized_arg_list);  // TODO
	ft_putstr_fd(str, 1);
	str_len = (int)ft_strlen(str);
	// termination_protocol(ap, stylized_arg_list);
	return (str_len);
}
