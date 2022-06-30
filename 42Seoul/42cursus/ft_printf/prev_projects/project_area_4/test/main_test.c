/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:16:48 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/26 16:25:35 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "stdio.h"

void test1(int n, ...)
{
	va_list ap;

	// printf("%p\n", ap);
	va_start(ap, n);
	printf("%p\n", ap);
	va_end(ap);
	printf("%p\n", ap);
	va_end(ap);
	printf("%p\n", ap);
}

int stop_by_making_error(void)
{
	int arr[3];
	int a;
	a = arr[3];
	return a;
}

int	main(void)
{
	int a = 10;
	// test_for_using_libft("Hello world!\n");
	// test_for_using_my_itoa(123456);
	printf("|%-10%|\n");
	printf("|%.10d|\n", a);
	printf("|%lu|\n", sizeof(char));
	printf("|%lu|\n", sizeof(unsigned char));
	printf("|%lu|\n", sizeof(short int));
	printf("|%lu|\n", sizeof(unsigned short int));
	printf("|%lu|\n", sizeof(__int32_t));
	printf("|%lu|\n", sizeof(__int64_t));
	printf("|%lu|\n", sizeof(intmax_t));
	printf("|%lu|\n", sizeof(long int));
	printf("|%lu|\n", sizeof(long unsigned int));
	printf("|%lu|\n", sizeof(long long int));
	printf("|%lu|\n", sizeof(unsigned long long int));
	printf("|%lu|\n", sizeof(size_t));
	printf("|%lu|\n", 9223372036854775807);
	printf("|%lu|\n", sizeof(9223372036854775807));


	printf("-----------\n");
	test1(3, 'a', 'b', 'c');
	printf("-----------\n");
	// if (NULL == '\0')
	// 	printf("YES!!\n");
	stop_by_making_error();
	return (0);
}