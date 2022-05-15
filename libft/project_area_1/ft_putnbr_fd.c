/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:44:23 by seoyoo            #+#    #+#             */
/*   Updated: 2022/05/04 16:07:56 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_positive_int(size_t n, int fd)
{
	int	reverse_num_buffer[10];
	int	i;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	i = 0;
	while (n > 0)
	{
		reverse_num_buffer[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(fd, &reverse_num_buffer[i], 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}	
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	put_positive_int(n, fd);
}
