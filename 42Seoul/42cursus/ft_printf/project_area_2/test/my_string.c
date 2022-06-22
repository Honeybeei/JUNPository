/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:49:27 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/22 17:08:54 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_string.h"

// Discription
// Join string which starts from start(1st param) and ends before end(2nd param)
// and join to dest(3rd param)

// 1st Parameter :	The address of first char of string which will be joined to 
// dest
// 2nd Parameter :	The address if the char which will be the next char of the 
// last character of joined string.
// 3rd Parameter :  The prefix string
// Return values :	Malloced concatenated string
char *my_cut_n_join(char *start, char *end, char *dest)
{
	char *s1;

	s1 = malloc(sizeof(char) * (end - start + 1));
	if (s1 == NULL)
		return (NULL);
	
	
}