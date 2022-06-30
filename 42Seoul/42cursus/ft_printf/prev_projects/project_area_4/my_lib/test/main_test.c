/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:54:52 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/21 16:55:06 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "my_itoa.h"
#include <stdio.h>

int main(void)
{
	char *str = my_itoa(256, "0123456789abcdef");
	printf("my_itoa test : %s\n",str);
	free(str);
	return 0;
}