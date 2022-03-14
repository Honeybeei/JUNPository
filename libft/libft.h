/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:15:07 by seoyoo            #+#    #+#             */
/*   Updated: 2022/03/12 16:41:07 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <unistd.h>

int		ft_isalpha(char c);
int		ft_isdigit(int n);
int		ft_isalnum(int c);
int		ft_ascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);

char	ft_toupper(char c);

#endif