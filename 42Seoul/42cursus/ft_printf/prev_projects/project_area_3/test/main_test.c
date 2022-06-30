/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:16:48 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/24 12:26:36 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "stdio.h"



int	main(void)
{
	printf("%d\n", ft_printf());
	test_for_using_libft("Hello world!\n");
	test_for_using_my_itoa(123456);
	
	return (0);
}