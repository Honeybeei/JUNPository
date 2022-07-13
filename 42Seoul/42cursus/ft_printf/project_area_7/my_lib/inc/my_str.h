/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:51:51 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/04 15:46:25 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_STR_H
# define MY_STR_H

# include <stdlib.h>
# include "libft.h"

// my_str.c
char	*my_strjoin_n_free(char *s1, char *s2);
char	*my_strjoin_n_free_s1(char *s1, const char *s2);
char	*my_strjoin_n_free_s2(const char *s1, char *s2);

#endif