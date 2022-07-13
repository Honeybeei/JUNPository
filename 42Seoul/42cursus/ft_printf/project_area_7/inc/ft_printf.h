/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:40:15 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/13 21:11:49 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../my_lib/inc/libft.h"
# include "../my_lib/inc/my_itoa.h"
# include "../my_lib/inc/my_str.h"
# include <stdlib.h> // malloc, free
# include <unistd.h> // write
# include <stdarg.h> // va_start, va_arg, va_copy, va_end

# define TURE 1
# define FALIE 0

typedef struct s_flag
{
	char	minus_;
	char	plus_;
	char	zero_;
	char	space_;
	char	hash_;
}	t_flag;

// %[flags][width][.precision][size]type
typedef struct s_format_specification
{
	t_flag	flag_;
	int		width_;
	int		precision_;
	size_t	size_;
	char	type_;
}	t_f_spec;

typedef struct s_format
{
	t_f_spec		*spec;
	char			*str;
	struct s_format	*next;
}	t_fmt;

#endif