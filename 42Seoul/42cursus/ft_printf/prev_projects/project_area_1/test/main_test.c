/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:54:52 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/22 17:08:01 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "my_itoa.h"
#include <stdio.h>

typedef struct test_struct
{
	void *n;
} test_struct;


int main(void)
{
	test_struct struct1;

	struct1.n = "Hello wrold!";

	printf("%lu", sizeof(struct1.n));
	printf("\n%s\n", struct1.n);
	return 0;
}