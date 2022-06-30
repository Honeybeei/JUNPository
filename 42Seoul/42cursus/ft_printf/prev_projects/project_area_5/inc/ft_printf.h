/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:57:09 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/28 22:25:42 by seoyoo           ###   ########.fr       */
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

typedef struct s_fmt
{
	char			*str;
	struct s_fmt	*next;
} t_fmt;


// makefile_test1.c
void	test_for_using_libft(char *str);

// ft_printf.c
int		ft_printf(const char *format, ...);

// read_format.c
char	*read_format(char *str, va_list ap ,t_fmt *node);




#endif