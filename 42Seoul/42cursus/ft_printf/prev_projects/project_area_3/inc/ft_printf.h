/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:57:09 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/24 22:45:48 by seoyoo           ###   ########.fr       */
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
	char size[3];
	char type;
} t_spec;

typedef struct s_fmt
{
	t_spec spec;
	char *pre_str;
	char *str;
} t_fmt;



// makefile_test1.c
void	test_for_using_libft(char *str);
void	test_for_using_my_itoa(long long n);

// ft_printf.c
int		ft_printf(const char *format, ...);
char	**convert_args_to_strs(char *str, va_list ap);
int		count_fmt_specs(char *str);
char	*read_fmt_spec(char *str, t_fmt *fmt, va_list ap);
char	*analyze_fmt_spec(char *str, t_spec *spec, va_list ap);


#endif