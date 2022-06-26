/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:57:09 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/26 19:26:57 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../my_lib/inc/libft.h"
# include "../my_lib/inc/my_itoa.h"
# include <stdbool.h>
# include <stdlib.h> // malloc, free
# include <unistd.h> // write
# include <stdarg.h> // va_start, va_arg, va_copy, va_end

# define ERROR -1
# define SIZE_SPEC_BUFF 4

typedef struct s_flag
{
	bool	minus;
	bool	plus;
	bool	zero;
	bool	space;
	bool	hash;
} t_flag;

// %[flags][width][.precision][size]type
typedef struct s_spec
{
	t_flag flag;
	int specified_width;
	int precision;
	char size[SIZE_SPEC_BUFF];
	char type;
} t_spec;

typedef struct s_fmt
{
	t_spec	*spec;
	char	*str;
	struct s_fmt *next;
} t_fmt;


// makefile_test1.c
void	test_for_using_libft(char *str);
void	test_for_using_my_itoa(long long n);

// ft_printf.c
int		ft_printf(const char *format, ...);
t_fmt	**read_str(va_list ap, char *str);

// utils.c
char	is_type_spec(char c);
char	is_flag_spec(char c);
char	is_num(char c);

// fmt_list.c
t_fmt	*new_t_fmt_node(t_fmt **tail);

// read_fmt_spec_1.c
char	*read_fmt_spec(char *str, va_list ap, t_fmt *new_node);
void	initialize_fmt_spec(t_spec *spec);
void	initialize_flag(t_flag *flag);
char	*read_flag(char *str, t_spec *spec);
int		switch_flag(char c, t_flag flag);

// read_fmt_spec_2.c
char	*read_width(char *str, t_spec *spec, va_list ap);
char	*read_precision(char *str, t_spec *spec, va_list ap);
char	*read_size(char *str, t_spec *spec);
char	*read_type(char *str, t_spec *fmt_spec);

// check_validity.c
int check_fmt_spec_syntax_vld(char *str);
int check_fmt_spec_vld(t_spec *spec);


#endif