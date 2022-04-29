/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:06:40 by seoyoo            #+#    #+#             */
/*   Updated: 2022/04/29 11:55:18 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_filter(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (0);
	else if (c == '\f' || c == '\r' || c == ' ')
		return (0);
	else if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	else if ('0' <= c && c <= '9')
		return (2);
	else
		return (3);
}

int	ft_atoi(const char *str)
{
	char		*temp;
	long long	result;
	int			plus_minus_sign;

	if (str == NULL)
		return (0);
	temp = (char *)str;
	result = 0;
	plus_minus_sign = 1;
	while (char_filter(*temp) == 0)
		temp++;
	if (char_filter(*temp) == 1 || char_filter(*temp) == -1)
	{
		plus_minus_sign *= char_filter(*temp);
		temp++;
	}
	while (char_filter(*temp) == 2)
	{
		result *= 10;
		result += *temp - '0';
		temp++;
	}
	return ((int)(result * plus_minus_sign));
}
