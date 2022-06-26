/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makefile_test1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:47:36 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/24 12:16:36 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test_for_using_libft(char *str)
{
	ft_putstr_fd(str, 1);
}

void	test_for_using_my_itoa(long long n)
{
	char *numstr;

	numstr = "0123456789";
	ft_putstr_fd(my_itoa(n, numstr), 1);
}
