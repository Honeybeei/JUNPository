/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:16:48 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/28 22:44:58 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	test_function_1(int arg_cnt, ...)
{
	va_list	ap;
	unsigned long long int n1;

	va_start(ap, arg_cnt);
	for (int i = 0; i < arg_cnt; i++)
	{
		printf("%p\n", ap);
		n1 = (unsigned long long)va_arg(ap, void *);
		printf("%llu\n", n1);
	}
}

int	main(void)
{
	unsigned int a;
	int b;

	a = 42;
	b = 4242;
	test_function_1(2, a, b);
	return 0;
}