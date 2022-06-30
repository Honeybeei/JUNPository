/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_itoa.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:13:29 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/28 20:00:48 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_ITOA_H
# define MY_ITOA_H

#include <stdlib.h>
#include "libft.h"

typedef struct s_my_signed_num
{
	long long	n;
	int			base;
	char		*symbol_list;
	char		*num_str;
} t_my_num;

char	*my_itoa(long long n, char *symbol_list);
int		count_digit(t_my_num *num);
void	fill_str(t_my_num *num, int str_len);

#endif