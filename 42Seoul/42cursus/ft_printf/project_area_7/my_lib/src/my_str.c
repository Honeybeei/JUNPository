/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:50:39 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/04 15:45:59 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/my_str.h"

// only use this function when s1 and s2 is mallocated char *
char	*my_strjoin_n_free(char *s1, char *s2)
{
	char	*joined_str;

	joined_str = NULL;
	joined_str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (joined_str);
}

char	*my_strjoin_n_free_s1(char *s1, const char *s2)
{
	char	*joined_str;

	joined_str = NULL;
	joined_str = ft_strjoin(s1, s2);
	free(s1);
	return (joined_str);
}

char	*my_strjoin_n_free_s2(const char *s1, char *s2)
{
	char	*joined_str;

	joined_str = NULL;
	joined_str = ft_strjoin(s1, s2);
	free(s2);
	return (joined_str);
}
