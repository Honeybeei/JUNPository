/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:24:28 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/03 15:43:35 by seoyoo           ###   ########.fr       */
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
		// TODO : CHECK_FLAG_COMB_VLD
		// TODO : CHECK_TYPE_FLAG_COMB_VLD
		// TODO : CHECK_TYPE_PRECISION_COMB_VLD
	char	*parse_fmt_spec(char *str, va_list ap, t_fmt *new_node);
		void	initialize_fmt_spec(t_spec *spec);
			void	initialize_flag(t_flag *flag);
		char	*read_flag(char *str, t_spec *spec);
			int	switch_flag(char c, t_flag flag);
		char	*read_width(char *str, t_spec *spec, va_list ap);
		char	*read_precision(char *str, t_spec *spec, va_list ap);
		char	*read_size(char *str, t_spec *spec);
		char	*read_type(char *str, t_spec *spec);
	
	char	*stylize_arg_to_str(t_spec *spec, va_list ap);
		char	*stylize_c_type_arg(t_spec *spec, va_list ap);


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
		if (new_node->str == NULL)
			return (NULL);
	}
	return (head);
}

t_fmt	*add_new_t_fmt_node(t_fmt **tail)
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

char	*parse_fmt_spec(char *str, va_list ap, t_fmt *new_node)
{
	initialize_fmt_spec(new_node->spec);
	str = read_flag(str, new_node->spec);
	str = read_width(str, new_node->spec, ap);
	str = read_precision(str, new_node->spec, ap);
	str = read_size(str, new_node->spec);
	str = read_type(str, new_node->spec);
	new_node->str = stylize_arg_to_str(new_node->spec, ap);
		if (new_node->str == NULL)
			return (NULL);
	return (str);
}

void	initialize_fmt_spec(t_spec *spec)
{
	initialize_flag(&(spec->flag));
	spec->specified_width = 0;
	spec->precision = -1;
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
			spec->precision = 0;
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

// stylelize argument with format specfication and return stylized string
char	*stylize_arg_to_str(t_spec *spec, va_list ap)
{
	char type;
	char *temp_str;

	type = spec->type;
	if (type == 'c')
		temp_str = stylize_c_type_arg(spec, ap);
	else if (type == 's')
		temp_str = stylize_s_type_arg(spec, ap);
	else if (type == 'p')
		temp_str = stylize_p_type_arg(spec, ap);
	else if (type == 'd' || type == 'i')
		temp_str = stylize_signed_int_type_arg(spec, ap);
	else if (type == 'u' || type == 'x' || type == 'X')
		temp_str = stylize_unsigned_int_type_arg(spec, ap);
	else
		return (NULL);
	return (manage_str_width(spec, temp_str));
}

// apply size->precision->flag excluding width to argument and get string
char	*stylize_c_type_arg(t_spec *spec, va_list ap)
{
	char *str;

	str = malloc(sizeof(char) * 2);
	str[0] = va_arg(ap, int);
	str[1] = '\0';
	return (str);
}

char	*stylize_s_type_arg(t_spec *spec, va_list ap)
{
	char	*str;
	char	*sub_str;
	size_t	str_len;

	str = va_arg(ap, char *);
	str_len = ft_strlen(str);
	if (str_len < spec->precision)
		return (ft_substr(str, 0, spec->precision));
	else
		return (ft_strdup(str));
}

char	*stylize_p_type_arg(t_spec *spec, va_list ap)
{
	unsigned long long int n;
	char *str;
	char *new_str;

	n = va_arg(ap, long long);
	str = my_itoa_unsigned(n, "0123456789abcdef");
	new_str = ft_strjoin('0x', str);
	free(str);
	return (new_str);
}

char	*stylize_signed_int_type_arg(t_spec *spec, va_list ap)
{
	long long n;


	if (spec->size <= sizeof(int))
		n = va_arg(ap, int);
	else if (spec->size == sizeof(long))
		n = va_arg(ap, long);
	else
		n = va_arg(ap, long long);
	
}
// return padded(if) stylized string
char	*manage_str_width(t_spec *spec, char *temp_str)
{
	size_t	temp_str_len;
	size_t	margin_str_len;
	char	*margin_str;
	char	*padded_str;

	temp_str_len = ft_strlen(temp_str);
	if (spec->specified_width > temp_str_len)
	{
		margin_str_len = spec->specified_width - temp_str_len;
		if (spec->flag.zero)
			margin_str = make_margin_str('0', margin_str_len);
		else
			margin_str = make_margin_str(' ', margin_str_len);
		if (spec->flag.minus)
			padded_str = ft_strjoin(temp_str, margin_str);
		else
			padded_str = ft_strjoin(margin_str, temp_str);
		free(temp_str);
		free(margin_str);
		return (padded_str);
	}
	else
		return (temp_str);
}

char	*make_margin_str(char c, size_t len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_memset(str, c, len);
	str[len] = '\0';
	return (str);
}