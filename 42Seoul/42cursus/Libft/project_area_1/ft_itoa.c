/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:17:28 by seoyoo            #+#    #+#             */
/*   Updated: 2022/05/04 12:05:09 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_buff_size(int n)
{
	size_t	buff_size;

	buff_size = 2;
	if (n < 0)
		buff_size++;
	while (1)
	{
		n /= 10;
		if (n == 0)
			return (buff_size);
		buff_size++;
	}
}

void	exception_handling(int n, char *num_str)
{
	if (n == -2147483648)
		ft_strlcpy(num_str, "-2147483648", 12);
	else if (n == 0)
		ft_strlcpy(num_str, "0", 2);
}

void	put_nbr_to_str(int n, char *num_str, size_t buff_size)
{
	if (n < 0)
	{
		num_str[0] = '-';
		n = -n;
	}
	buff_size--;
	num_str[buff_size] = '\0';
	while (n > 0)
	{
		buff_size--;
		num_str[buff_size] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	buff_size;
	char	*num_str;

	buff_size = get_buff_size(n);
	num_str = (char *)malloc(sizeof(char) * buff_size);
	if (num_str == NULL)
		return (NULL);
	if (n == 0 || n == -2147483648)
		exception_handling(n, num_str);
	else
		put_nbr_to_str(n, num_str, buff_size);
	return (num_str);
}
