/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:57:09 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/03 20:00:51 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../my_lib/inc/libft.h"
# include "../my_lib/inc/my_itoa.h"
# include "../my_lib/inc/my_str.h"
# include <stdbool.h>
# include <stdlib.h> // malloc, free
# include <unistd.h> // write
# include <stdarg.h> // va_start, va_arg, va_copy, va_end

# define PRINT_ERROR 0  // switch for print error. 0 for no, 1 for yes
# define ERROR -1
# define FMT_SPEC_SYNTAX_ERROR -2
# define FMT_SPEC_COMBINATION_ERROR -3
# define INITIAL_PRECISION_VALUE -1  // should not be zero

typedef struct s_flag
{
	bool	minus;
	bool	plus;
	bool	zero;
	bool	space;
	bool	hash;
}	t_flag;

// %[flags][width][.precision][size]type
typedef struct s_spec
{
	t_flag	flag;
	int		specified_width;
	int		precision;
	size_t	size;
	char	type;
}	t_spec;

typedef struct s_fmt
{
	t_spec			*spec;
	char			*str;
	struct s_fmt	*next;
}	t_fmt;

#endif