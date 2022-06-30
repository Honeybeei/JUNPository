/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:21:19 by seoyoo            #+#    #+#             */
/*   Updated: 2022/06/24 15:14:04 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_my_str
{
	char	*str;
	size_t	len;
} t_my_str;

t_my_str *make_my_str(char *str)
{
	t_my_str *my_str;

	my_str = malloc(sizeof(t_my_str));
	my_str->str = ft_strdup;
	my_str->len = ft_strlen(str);
	return (my_str);
}
