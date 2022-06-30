/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:24:28 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/30 15:01:29 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_printf(const char *format, ...);

t_fmt	**parse_string(char *str, va_list ap);
	t_fmt	*add_new_t_fmt_node(t_fmt **tail);
	bool	check_fmt_spec_syntax_vld(char *str);
		bool	is_flag_spec(char c);
		bool	is_vld_size_type_comb(char *str);
			bool	is_h_comb_valid(char *str);
			bool	is_l_comb_valid(char *str);
	char	*parse_fmt_spec(char *str, va_list ap, t_fmt *new_node);
		void	initialize_fmt_spec(t_spec *spec);
			void	initialize_flag(t_flag *flag);
		char	*read_flag(char *str, t_spec *spec);
			int	switch_flag(char c, t_flag flag);
		char	*read_width(char *str, t_spec *spec, va_list ap);
		char	*read_precision(char *str, t_spec *spec, va_list ap);
		char	*read_size(char *str, t_spec *spec);
		char	*read_type(char *str, t_spec *spec);
	



	char	*read_plain_str(char *str, t_fmt *new_node);
int		print_stylized_str(t_fmt **head);
void	termination_protocol(va_list ap, t_fmt **head);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	t_fmt	**head;
	int		char_count;

	str = (char *)format;
	va_start(ap, format);
	if (*str == '\0')
		return (0);
	head = parse_string(str, ap);
	if (head == NULL)
		return (ERROR);
	char_count = print_stylized_str(head);
	termination_protocol(ap, head);
	return (char_count);
}

t_fmt	**parse_string(char *str, va_list ap)
{
	t_fmt	**head;
	t_fmt	**tail;
	t_fmt	*new_node;

	head = NULL;
	tail = head;
	while (*str)
	{
		new_node = add_new_t_fmt_node(tail);
		if (head == NULL)
			*head = new_node;
		if (*str == '%')
		{
			str++;
			if (check_fmt_spec_syntax_vld(str))
				str = parse_fmt_spec(str, ap, new_node);
			else
				return (NULL);
		}
		else
			str = read_plain_str(str, new_node);
	}
	return (head);
}

t_fmt *add_new_t_fmt_node(t_fmt **tail)
{
	t_fmt	*new_node;

	new_node = malloc(sizeof(t_fmt));
	if (new_node == NULL)
		return (NULL);
	(*tail)->next = new_node;
	new_node->next = NULL;
	*tail = new_node;
	new_node->spec = NULL;
	new_node->str = NULL;
	return (new_node);
}

bool check_fmt_spec_syntax_vld(char *str)
{
	if (*str == '%')
		return (true);
	while (is_flag_spec(*str))
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (is_vld_size_type_comb(str))
		return (true);
	return (false);
}

bool	is_flag_spec(char c)
{
	if (ft_strchr("-+ #0", c) == NULL)
		return (false);
	else
		return (true);
}

bool	is_vld_size_type_comb(char *str)
{
	if (ft_strchr("cspdiuxX", *str) || *str == '%')
		return (true);
	else if (*str == 'h')
		return (is_h_comb_valid(str));
	else if (*str == 'l')
		return (is_l_comb_valid(str));
	else
		return (false);
}

bool	is_h_comb_valid(char *str)
{
	if (ft_strchr("diuxX", *(str + 1)))
		return (true);
	else if (*(str + 1) == 'h')
	{
		if (ft_strchr("diuxX", *(str + 2)))
			return (true);
	}
	else
		return (false);
}

bool	is_l_comb_valid(char *str)
{
	if (ft_strchr("cdiuxX", *(str + 1)))
		return (true);
	else if (*(str + 1) == 'l')
	{
		if (ft_strchr("diuxX", *(str + 2)))
			return (true);
	}
	else
		return (false);
}

char	*parse_fmt_spec(char *str, va_list ap, t_fmt *new_node)
{
	initialize_spec(new_node->spec);
	str = read_flag(str, new_node->spec);
	str = read_width(str, new_node->spec, ap);
	str = read_precision(str, new_node->spec, ap);
	str = read_size(str, new_node->spec);
	str = read_type(str, new_node->spec);
	stylize_arg_to_str(new_node, ap);
	return (str);
}

void	initialize_fmt_spec(t_spec *spec)
{
	initialize_flag(&(spec->flag));
	spec->specified_width = 0;
	spec->precision = 0;
	spec->size = 0;
	spec->type = 0;
}

void	initialize_flag(t_flag *flag)
{
	flag->minus = false;
	flag->plus = false;
	flag->zero = false;
	flag->space = false;
	flag->hash = false;
}

char	*read_flag(char *str, t_spec *spec)
{
	str++;
	while (switch_flag(*str, spec->flag))
		str++;
	return (str);
}

int	switch_flag(char c, t_flag flag)
{
	if (c == '-')
		flag.minus = true;
	else if (c == '+')
		flag.plus = true;
	else if (c == '0')
		flag.zero = true;
	else if (c == ' ')
		flag.space = true;
	else if (c == '#')
		flag.hash = true;
	else
		return (0);
	return (1);
}

char	*read_width(char *str, t_spec *spec, va_list ap)
{
	if (*str == '*')
	{
		spec->specified_width = va_arg(ap, int);
		str++;
	}
	else
	{
		while ('0' <= *str && *str <= '9')
		{
			spec->specified_width *= 10;
			spec->specified_width += *str - '0';
			str++;
		}
	}
	return (str);
}

char	*read_precision(char *str, t_spec *spec, va_list ap)
{
	if (*str == '.')
	{
		str++;
		if (*str == '*')
		{
			spec->precision = va_arg(ap, int);
			str++;
		}
		else
		{
			while ('0' <= *str && *str <= '9')
			{
				spec->precision *= 10;
				spec->precision += *str - '0';
				str++;
			}
		}
	}
	return (str);
}

char	*read_size(char *str, t_spec *spec)
{
	if (*str == 'h')
	{
		if (*(str + 1) == 'h')
		{
			spec->size = (int)sizeof(char);
			return (str + 2);
		}
		spec->size = (int)sizeof(short int);
		return (str + 1);
	}
	else if (*str == 'l')
	{
		if (*(str + 1) == 'l')
		{
			spec->size = (int)sizeof(long long int);
			return (str + 2);
		}
		spec->size = (int)sizeof(long int);
		return (str + 1);
	}
	else
	{
		spec->size = (int)sizeof(int);
		return (str);
	}
}

char	*read_type(char *str, t_spec *spec)
{
	spec->type = *str;
	return (str + 1);
}

stylize_arg_to_str(new_node, ap)



