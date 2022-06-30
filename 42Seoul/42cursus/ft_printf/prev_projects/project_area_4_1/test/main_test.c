/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:16:48 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/28 17:40:34 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "stdio.h"

// void test1(int n, ...)
// {
// 	va_list ap;

// 	// printf("%p\n", ap);
// 	va_start(ap, n);=
// 	printf("%p\n", ap);
// 	va_end(ap);
// 	printf("%p\n", ap);
// 	va_end(ap);
// 	printf("%p\n", ap);
// }

int	main(void)
{
	char a = -1;
	short b = -42;
	int c = 42;
	long d = 123456;
	long long e = 123456789;
	char *s = "Hello";

	printf("type - size matching test\n\n");
	printf("%hu\n", b);
}