/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:32:49 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/06 23:23:10 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>  // open

#define FILE "test/gnl_test.txt"

int main(void)
{
    int fd = open(FILE, O_RDONLY);
    char *str = get_next_line(fd);
    printf("|%s|", str);
    return (0);
}