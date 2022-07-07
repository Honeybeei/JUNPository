/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:16:48 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/04 15:14:14 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

void testtest(size_t count, ...)
{
	va_list ap;
	long long int n;

	va_start(ap, count);
	n = va_arg(ap, int);
	printf("%lld\n", n);
}



int	main(void)
{
	// char *str = "<123456789>";
	// int c = 42;

	// printf("|%20.12d|\n", c);
	// printf("|%-+20.6d|\n", c);
	// printf("|%-20d|\n", c);
	// printf("|%020d|\n", c);
	// printf("|% -20.12d|\n", c);
	// printf("|%#20d|\n", c);

	// printf("|%020.12u|\n", c);
	// printf("|%+20u|\n", c);
	// printf("|%-20u|\n", c);
	// printf("|%020u|\n", c);
	// printf("|% 20u|\n", c);
	// printf("|%#20u|\n", c);

	// printf("|%20.12x|\n", c);
	// printf("|%+20.12x|\n", c);
	// printf("|%-20x|\n", c);
	// printf("|%020x|\n", c);
	// printf("|% 20x|\n", c);
	// printf("|%#20.8x|\n", c);

	// printf("|%20.12X|\n", c);
	// printf("|%+20.12X|\n", c);
	// printf("|%-20X|\n", c);
	// printf("|%020X|\n", c);
	// printf("|% 20X|\n", c);
	// printf("|%-#20.8X|\n", c);

	// printf("|%20.3%|\n");
	// printf("|%-20%|\n");
	// printf("|%+20%|\n");
	// printf("|% 20%|\n");
	// printf("|%#20%|\n");
	// printf("|%0.3%|\n");

	// printf("|%20.12c|\n", c);
	// printf("|%+20.12c|\n", c);
	// printf("|%-20c|\n", c);
	// printf("|%020c|\n", c);
	// printf("|% 20c|\n", c);
	// printf("|%-#20.8c|\n", c);

	// size_t n1 = 123;
	// int n2 = -2;
	// if ((int)n1 > n2)
	// 	printf("Hello!\n");
	// else
	// 	printf("NOOOOO\n");

	testtest(1, 123456);

	return 0;
}