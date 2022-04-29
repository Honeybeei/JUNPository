/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:22:33 by seoyoo            #+#    #+#             */
/*   Updated: 2022/04/29 14:32:42 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s_temp;

	if (s == NULL)
		return ;
	s_temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s_temp[i] = 0;
		i++;
	}
	s = s_temp;
}
