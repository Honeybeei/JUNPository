/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:24:28 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/04 15:53:25 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf(const char *format, ...);
	int	parse_str_make_linked_list(char *str, va_list ap, t_fmt **head);
		t_fmt	*add_new_t_fmt_node(t_fmt **head, t_fmt **tail);
		bool	check_fmt_spec_syntax_vld(char *str);
			bool	is_flag_spec(char c);
			bool	is_vld_size_type_comb(char *str);
				bool	is_h_comb_valid(char *str);
				bool	is_l_comb_valid(char *str);
		char	*parse_fmt_spec(char *str, va_list ap, t_spec *spec);
			void	initialize_fmt_spec(t_spec *spec);
				void	initialize_flag(t_flag *flag);
			char	*read_flag(char *str, t_spec *spec);
				int	switch_flag(char c, t_flag *flag);
			char	*read_width(char *str, t_spec *spec, va_list ap);
			char	*read_precision(char *str, t_spec *spec, va_list ap);
			char	*read_size(char *str, t_spec *spec);
			char	*read_type(char *str, t_spec *spec);
		bool	check_fmt_spec_combination_vld(t_spec *spec);
			bool	check_flag_flag_comb_vld(t_spec *spec);
			bool	check_type_flag_comb_vld(t_spec *spec);
				bool	check_is_vld_flag(t_flag *flag, char *available_flag_str);
					bool	check_flag_identity(t_flag *flag_to_be_checked, t_flag *available_flag);
			bool	check_type_precision_comb_vld(t_spec *spec);
		char	*stylize_arg_to_str(t_spec *spec, va_list ap);
			char	*stylize_c_type_arg(t_spec *spec, va_list ap);
				char	*add_padding_without_sign(t_spec *spec, char *str, char padd_char);
					char	*padd_left(size_t padding_len, char *str, char padd_char);
					char	*padd_right(size_t padding_len, char *str, char padd_char);
			char	*stylize_s_type_arg(t_spec *spec, va_list ap);
			char	*stylize_p_type_arg(t_spec *spec, va_list ap);
			char	*stylize_signed_int_type_arg(t_spec *spec, va_list ap);








	int		print_linked_list(t_fmt *head);
	void	termination_protocol();  // TODO

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	t_fmt	**head;
	int		printed_char_count;
	int		parsing_result;

	va_start(ap, format);
	str = (char *)format;
	if (str == NULL || *str == '\0')
		return (0);
	head = NULL;
	parsing_result = parse_str_make_linked_list(str, ap, head);
	if (parsing_result == 1)
		printed_char_count = print_linked_list(head);
	else
	{
		print_error(PRINT_ERROR, parsing_result);
		printed_char_count = parsing_result;
	}
	termination_protocol();  // TODO : ap, head
	return (printed_char_count);
}

int	parse_str_make_linked_list(char *str, va_list ap, t_fmt **head)
{
	t_fmt	**tail;
	t_fmt	*new_node;

	while (*str)
	{
		new_node = add_new_t_fmt_node(head, tail);
		if (*str == '%')
		{
			str++;
			if (!check_fmt_spec_syntax_vld(str))
				return (FMT_SPEC_SYNTAX_ERROR);
			str = parse_fmt_spec(str, ap, new_node);
			if (!check_fmt_spec_combination_vld(new_node->spec))
				return (FMT_SPEC_COMBINATION_ERROR);
			new_node->str = stylize_arg_to_str(new_node->spec, ap);
		}
		else
			str = read_plain_str(str, new_node);
	}
	return (1);
}

t_fmt	*add_new_t_fmt_node(t_fmt **head, t_fmt **tail)
{
	t_fmt	*new_node;

	new_node = malloc(sizeof(t_fmt));
	if (new_node == NULL)
		return (NULL);
	new_node->spec = NULL;
	new_node->str = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		*tail = new_node;
	}
	else
	{
		(*tail)->next = new_node;
		new_node->next = NULL;
		*tail = new_node;
	}
	return (new_node);
}

bool check_fmt_spec_syntax_vld(char *str)
{
	if (*str == '%')
		return (true);
	while (is_flag_spec(*str))
		str++;
	if (*str == '*')
		str++;
	else
	{
		while (ft_isdigit(*str))
			str++;
	}
	if (*str == '.')
	{
		str++;
		if (*str == '*')
			str++;
		else
		{
			while (ft_isdigit(*str))
				str++;
		}
	}
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
	return (false);
}

char	*parse_fmt_spec(char *str, va_list ap, t_spec *spec)
{
	initialize_fmt_spec(spec);
	str = read_flag(str, spec);
	str = read_width(str, spec, ap);
	str = read_precision(str, spec, ap);
	str = read_size(str, spec);
	str = read_type(str, spec);
	return (str);
}

void	initialize_fmt_spec(t_spec *spec)
{
	initialize_flag(&(spec->flag));
	spec->specified_width = 0;
	spec->precision = INITIAL_PRECISION_VALUE;
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
	while (switch_flag(*str, &(spec->flag)))
		str++;
	return (str);
}

int	switch_flag(char c, t_flag *flag)
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
		spec->precision = 0;
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
	else
		return (str);
}

char	*read_size(char *str, t_spec *spec)
{
	if (*str == 'h')
	{
		if (*(str + 1) == 'h')
		{
			spec->size = sizeof(char);
			return (str + 2);
		}
		spec->size = sizeof(short);
		return (str + 1);
	}
	else if (*str == 'l')
	{
		if (*(str + 1) == 'l')
		{
			spec->size = sizeof(long long);
			return (str + 2);
		}
		spec->size = sizeof(long);
		return (str + 1);
	}
	else
	{
		spec->size = sizeof(int);
		return (str);
	}
}

char	*read_type(char *str, t_spec *spec)
{
	spec->type = *str;
	return (str + 1);
}

bool	check_fmt_spec_comb_vld(t_spec *spec)
{
	if (!check_flag_flag_comb_vld(spec))
		return (false);
	if (!check_type_flag_comb_vld(spec))
		return (false);
	if (!check_type_precision_comb_vld(spec))
		return (false);
	if (spec->flag.zero == true && spec->precision != INITIAL_PRECISION_VALUE)
		spec->flag.zero = false;
	return (true);
}

bool	check_flag_flag_comb_vld(t_spec *spec)
{
	if (spec->flag.space == true && spec->flag.plus == true)
		return (false);
	if (spec->flag.zero == true && spec->flag.minus == true)
		return (false);
	return (true);
}

bool	check_type_flag_comb_vld(t_spec *spec)
{
	if (spec->type == 'c')
		return (check_is_vld_flag(&(spec->flag), "l"));
	if (spec->type == 's')
		return (check_is_vld_flag(&(spec->flag), "l"));
	if (spec->type == 'p')
		return (check_is_vld_flag(&(spec->flag), "l"));
	if (spec->type == 'd' || spec->type == 'i')
		return (check_is_vld_flag(&(spec->flag), "-+ 0"));
	if (spec->type == 'u')
		return (check_is_vld_flag(&(spec->flag), "-0"));
	if (spec->type == 'x' || spec->type == 'X')
		return (check_is_vld_flag(&(spec->flag), "-0#"));
	return (false);
}

bool	check_is_vld_flag(t_flag *flag, char *available_flag_str)
{
	t_flag available_flag;

	initialize_flag(&available_flag);
	while (*available_flag_str)
	{
		switch_flag(*available_flag_str, &available_flag);
		available_flag_str++;
	}
	return (check_flag_identity(flag, &available_flag));
}

bool	check_flag_identity(t_flag *flag_to_be_checked, t_flag *available_flag)
{
	if (flag_to_be_checked->minus == true && available_flag->minus == false)
		return (false);
	if (flag_to_be_checked->plus == true && available_flag->plus == false)
		return (false);
	if (flag_to_be_checked->space == true && available_flag->space == false)
		return (false);
	if (flag_to_be_checked->hash == true && available_flag->hash == false)
		return (false);
	if (flag_to_be_checked->zero == true && available_flag->zero == false)
		return (false);
	return (true);
}

bool	check_type_precision_comb_vld(t_spec *spec)
{
	if (spec->type == 'c' || spec->type == 'p')
	{
		if (spec->precision != INITIAL_PRECISION_VALUE)
			return (false);
	}
	return (true);
}

char	*stylize_arg_to_str(t_spec *spec, va_list ap)
{
	char	type;
	char	*str;

	str = NULL;
	type = spec->type;
	if (type == 'c')
		str = stylize_c_type_arg(spec, ap);
	else if (type == 's')
		str = stylize_s_type_arg(spec, ap);
	else if (type == 'p')
		str = stylize_p_type_arg(spec, ap);
	else if (type == 'd' || type == 'i')
		str = stylize_signed_int_type_arg(spec, ap);
	else if (type == 'u' || type == 'x' || type == 'X')
		str = stylize_unsigned_int_type_arg(spec, ap)
	return (str);
}

char	*stylize_c_type_arg(t_spec *spec, va_list ap)
{
	char	*str;
	char	*padding_str;

	str = malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	str[0] = va_arg(ap, int);
	str[1] = '\0';
	str = add_padding_without_sign(spec, str);
	return (str);
}

char	*add_padding_without_sign(t_spec *spec, char *str, char padd_char)
{
	size_t	str_len;
	size_t	padding_len;
	char	*padded_str;

	if (spec->specified_width > str_len)
	{
		str_len = ft_strlen(str);
		padding_len = spec->specified_width - str_len;
		if (spec->flag.minus)
			padded_str = padd_left(padding_len, str, padd_char);
		else
			padded_str = padd_right(padding_len, str, padd_char);
		free(str);
		return (padded_str);
	}
	else
		return (str);
}

char	*padd_left(size_t padding_len, char *str, char padd_char)
{
	char	*padded_str;
	size_t	str_len;

	str_len = ft_strlen(str);
	padded_str = malloc(sizeof(char) * (padding_len + str_len + 1))
	if (padded_str == NULL)
		return (NULL);
	ft_memcpy(padded_str, str, str_len);
	ft_memset(padded_str + str_len, padd_char, padding_len);
	padded_str[padding_len + str_len] = '\0';
	return (padded_str);
}

char	*padd_right(size_t padding_len, char *str, char padd_char)
{
	char	*padded_str;
	size_t	str_len;

	str_len = ft_strlen(str);
	padded_str = malloc(sizeof(char) * (padding_len + str_len + 1))
	if (padded_str == NULL)
		return (NULL);
	ft_memset(padded_str, padd_char, padding_len);
	ft_memcpy(padded_str + padding_len, str, str_len);
	padded_str[padding_len + str_len] = '\0';
	return (padded_str);
}

char	*stylize_s_type_arg(t_spec *spec, va_list ap)
{
	char	*str;
	char	*sub_str;

	str = ft_strdup(va_arg(ap, char *));
	if (spec->precision < ft_strlen(str))
	{
		sub_str = ft_substr(str, 0, spec->precision);
		free(str);
		str = sub_str;
	}
	str = add_padding_without_sign(spec, str, ' ');
	return (str);
}

char	*stylize_p_type_arg(t_spec *spec, va_list ap)
{
	unsigned long long	address;
	char				*str;

	address = &(va_arg(ap, long long));
	str = my_itoa_unsigned(address, "0123456789abcdef");
	str = add_padding_without_sign(spec, str, ' ');
	return (str);
}

char	*stylize_signed_int_type_arg(t_spec *spec, va_list ap)  // TODO
{
	long long	n;

	if (spec->size <= sizeof(int))
		n = va_arg(ap, int);
	else if (spec->size <= sizeof(long))
		n = va_arg(ap, long);
	else
		n = va_arg(ap, long long);
	if (n > 0)
		return (stylize_pos_int(spec, n));
	else
		return (stylize_neg_int(spec, n));
}

char	*stylize_pos_int(t_spec *spec, long long n) 
{
	char	*sign;
	char	*str;
	size_t	str_len;
	char	*precision_appplied_str;

	sign = NULL;
	if (spec->flag.plus)
		sign = "+";
	if (spec->flag.space)
		sign = " ";
	str = my_itoa_signed(n, "0123456789");
	str_len = ft_strlen(str);
	if (spec->precision > str_len)
	{
		precision_appplied_str = padd_left(spec->precision - str_len, str, '0');
		free(str);
	}
	else
		precision_appplied_str = str;
	if (spec->specified_width > ft_strlen(precision_appplied_str))
		add_padding_to_pos_int(spec, precision_appplied_str, sign)
	else
		str = ft_strjoin()
}






