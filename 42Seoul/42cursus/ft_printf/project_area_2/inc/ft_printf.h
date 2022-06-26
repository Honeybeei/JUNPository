/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:57:09 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/23 21:38:46 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"
# include "./my_itoa.h"
# include <stdbool.h>
# include <stdlib.h> // malloc, free
# include <unistd.h> // write
# include <stdarg.h> // va_start, va_arg, va_copy, va_end

# define ERROR -1

typedef struct s_flag
{
	bool	minus;
	bool	plus;
	bool	zero;
	bool	space;
	bool	hash;
} t_flag;

// %[flags][width][.precision][size]type
typedef struct s_fmt_spec
{
	t_flag flag;
	int specified_width;
	int precision;
	char size[3];
	char type;
	char *pre_fmt_str;
	char *fmt_str;
} t_fmt_spec;

// ft_printf.c
int		ft_printf(const char *format, ...);

// get_stylized_arg_list0.c
char	**get_stylized_arg_list(char *str, va_list ap);
int		count_fmt_spec(char *str);
char	*arg_to_str(char *str, char *dst, va_list ap);

// read_fmt_spec0.c
char	*read_fmt_spec(char *str, va_list ap, t_fmt_spec *fmt_spec);
void	initialize_fmt_spec(t_fmt_spec *fmt_spec);
void	initialize_flag(t_flag *flag);
char	*read_flag(char *str, t_fmt_spec *fmt_spec);
int		switch_flag(char c, t_flag flag);

// read_fmt_spec1.c
char	*read_width(char *str, t_fmt_spec *fmt_spec, va_list ap);
char	*read_precision(char *str, t_fmt_spec *fmt_spec, va_list ap);
char	*read_size(char *str, t_fmt_spec *fmt_spec);
char	*read_type(char *str, t_fmt_spec *fmt_spec);
char	is_type_spec(char c);



#endif