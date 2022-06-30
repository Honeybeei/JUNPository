/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:57:09 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/21 20:59:01 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "my_itoa.h"
# include <stdbool.h>
# include <stdlib.h> // malloc, free
# include <unistd.h> // write
# include <stdarg.h> // va_start, va_arg, va_copy, va_end

# define FMT_ERROR -1
# define ARG_CNT_ERROR -2

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
} t_fmt_spec;

#endif