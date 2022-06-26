/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:56:05 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/25 10:25:04 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	**stylized_arg_list;
	char	*str;
	int		str_len;

	str = ft_strdup(format);
	va_start(ap, format);
	stylized_arg_list = convert_args_to_strs(str, ap);
	str = replace_fmt_spec(str, stylized_arg_list);  // TODO
	str_len = ft_strlen(str);
	termination_protocol(ap, str, stylized_arg_list);  // TODO
	return (str_len);
}

char **convert_args_to_strs(char *str, va_list ap)
{
	int		fmt_spec_cnt;
	t_fmt	*fmt_list;
	int		i;
	char	**stylized_arg_list;

	fmt_spec_cnt = count_fmt_specs(str);
	fmt_list = malloc(sizeof(t_fmt) * fmt_spec_cnt);
	if (fmt_list == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str = read_fmt_spec(str, &(fmt_list[i]), ap);
			i++;
		}
		else
			str++;
	}
	stylized_arg_list = get_strs_from_fmt_list(fmt_list);
	terminate_fmt_list(fmt_list);
	return (stylized_arg_list);
}

int	count_fmt_specs(char *str)
{
	int	fmt_spec_cnt;

	fmt_spec_cnt = 0;
	while (*str)
	{
		if (*str == '%')
		{
			fmt_spec_cnt++;
			if (*str == '%')
				str++;
		}
		str++;
	}
	return (fmt_spec_cnt);
}

char *read_fmt_spec(char *str, t_fmt *fmt, va_list ap)
{
	
	str = analyze_fmt_spec(str, &(fmt->spec), ap);
	stylize_arg_to_str(fmt, ap);
	return (str);
}

char *analyze_fmt_spec(char *str, t_spec *spec, va_list ap)
{
	str++;
	
}



char *replace_fmt_spec(char *str, char **stylized_arg_list)
{
	char **non_fmt_spec_parts;

	non_fmt_spec_parts = get_non_fmt_spec_parts(str);

}

printf