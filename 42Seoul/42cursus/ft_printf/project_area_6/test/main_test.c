/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:16:48 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/30 16:03:12 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>


// 알아보고 싶은 것 : va_arg에서 arg 읽어 올때 얼만 큼 읽어올까? 지정한 자료형 만큼?
void test_f(int count, ...)
{
	va_list ap;

	va_start(ap, count);
	char c = va_arg(ap, char);
	int i = va_arg(ap, int);
	long int li = va_arg(ap, long int);
	long long int lli = va_arg(ap, long long int);

	printf("%p\n", &c); 
	printf("%p\n", &i); 
	printf("%p\n", &li); 
	printf("%p\n", &lli); 

	printf("%llx\n", (unsigned long long int)&i - (unsigned long long int)&c);
	printf("%llx\n", (unsigned long long int)&li - (unsigned long long int)&i);
	printf("%llx\n", (unsigned long long int)&lli - (unsigned long long int)&li);


}

int	main(void)
{
	test_f(4, 'A', __INT_MAX__, __LONG_MAX__, __LONG_LONG_MAX__);
}