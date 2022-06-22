/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:53:45 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/22 17:16:04 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// ft_printf.c
int			ft_printf(const char *format, ...);

//  make_fmt_str_list.c
char		**make_fmt_str_list(char *str, va_list ap);
int			count_fmt_spec(char *str);
char		*read_fmt_spec(char *str, char *fmt_str, va_list ap);
void		initialize_fmt_spec(t_fmt_spec *fmt_spec);
void		initialize_flag(t_flag *flag);
char		*read_flag(char *str, t_fmt_spec *fmt_spec);
int			switch_flags(char c, t_flag *flag);


// print_format.c
int			print_format(char *str, char **fmt_str_list);

// termination_protocol.c
void		termination_protocol(char **fmt_str_lst);

int	ft_printf(const char *format, ...)
{
	char		*str;
	va_list		ap;
	char		**fmt_str_list;
	int			printed_char_cnt;

	str = (char *)format;
	if (format == NULL)
		return (FMT_ERROR);
	va_start(ap, format);
	fmt_str_list = make_fmt_str_list(str, ap);  // TODO
	printed_char_cnt = print_format(str, fmt_str_list);  // TODO
	termination_protocol(fmt_str_list); // free every malloced pointer  // TODO
	return (printed_char_cnt);
}

char	**make_fmt_str_list(char *str, va_list ap)
{
	char	**fmt_str_list;
	int		fmt_spec_cnt;
	int		i;

	fmt_spec_cnt = count_fmt_spec(str);
	fmt_str_list = malloc(sizeof(char *) * (fmt_spec_cnt + 1));
	if (fmt_str_list == NULL)
		return (NULL);
	fmt_str_list[fmt_spec_cnt] = '\0';
	if (fmt_spec_cnt == 0)
		return (fmt_str_list);
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str = read_fmt_spec(str, fmt_str_list[i], ap);  // TODO
			i++;
			if (i >= fmt_spec_cnt)
				break;
		}
		else
			str++;
	}
	return (fmt_str_list);
}

int	count_fmt_spec(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}

char	*read_fmt_spec(char *str, char *fmt_str, va_list ap)
{
	t_fmt_spec fmt_spec;

	initialize_fmt_spec(&fmt_spec);
	str = read_flag(str, &fmt_spec);
	str = read_width(str, &fmt_spec, ap);
	str = read_precision(str, &fmt_spec, ap);
	str = read_size(str, &fmt_spec);
	str = read_type(str, &fmt_spec);

	return (str);
}

void	initialize_fmt_spec(t_fmt_spec *fmt_spec)
{
	initialize_flag(&(fmt_spec->flag));
	fmt_spec->specified_width = 0;
	fmt_spec->precision = 0;
	ft_bzero(fmt_spec->precision, 3);
	fmt_spec->type = 0;
}

void	initialize_flag(t_flag *flag)
{
	flag->minus = false;
	flag->plus = false;
	flag->zero = false;
	flag->space = false;
	flag->hash = false;
}

char	*read_flag(char *str, t_fmt_spec *fmt_spec)
{
	str++;
	while (switch_flags(*str, &(fmt_spec->flag)))
		str++;
	return (str);
}

int	switch_flags(char c, t_flag *flag)
{
	if (c == '-')
		flag->minus = true;
	else if (c == '+')
		flag->plus = true;
	else if (c == '0')
		flag->zero = true;
	else if (c == ' ')
		flag->space = true;
	else if (c == '#')
		flag->hash = true;
	else
		return (0);
	return (1);
}

char	*read_width(char *str, t_fmt_spec *fmt_spec, va_list ap)
{
	if (*str == '*')
	{
		fmt_spec->specified_width = va_arg(ap, int);
		str++;
	}
	else
	{
		while ('0' <= *str && *str <= '9')
		{
			fmt_spec->specified_width *= 10;
			fmt_spec->specified_width += *str - '0';
			str++;
		}
	}
	return (str);
}





// termination_protocol.c
void	termination_protocol(char **fmt_str_lst)
{

}