/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:02:13 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/28 17:43:27 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	is_type_spec(char *c)
{
	char	*type_list;
	int		i;

	type_list = "cspdiuxX%";
	i = 0;
	while (type_list[i])
	{
		if (type_list[i] == *c)
			return (*c);
		i++;
	}
	return (0);
}

char	is_flag_spec(char *c)
{
	char	*flag_list;
	int		i;

	flag_list = "-+ #0";
	i = 0;
	while (flag_list[i])
	{
		if (flag_list[i] == *c)
			return (*c);
		i++;
	}
	return (0);
}

char	is_num(char *c)
{
	char	*num_list;
	int		i;

	num_list = "0123456789";
	i = 0;
	while (num_list[i])
	{
		if (num_list[i] == *c)
			return (*c);
		i++;
	}
	return (0);
}

char	is_size_n_type(char *c)
{
	char **size_n_type_list;

	size_n_type_list = {"c","hhi", "hhu", "hi", };


}