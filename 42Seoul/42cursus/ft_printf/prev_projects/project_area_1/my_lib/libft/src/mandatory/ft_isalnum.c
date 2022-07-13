/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:19:25 by seoyoo            #+#    #+#             */
/*   Updated: 2022/05/11 12:10:37 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Discription
// Tests if the c(1st Parameter) is an alphabet or a decimal or a single digit 
// character. 

// 1st Parameter :	Character to be checked.
// Return values :	Return 1 if c is an alphabet or a single digit character. 
//					Return 0 if its not. 

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}