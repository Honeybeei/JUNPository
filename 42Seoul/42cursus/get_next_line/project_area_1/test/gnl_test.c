/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:32:49 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/04 23:31:49 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#define FILE "test/gnl_test.txt"

int main(void)
{
    int     fd;
    char    buff[BUFFER_SIZE];
    size_t  i;

    fd = open(FILE, O_RDONLY);
    printf("fd : %d\n", fd);
    if (fd > 0)
    {
        read(fd, buff, BUFFER_SIZE);
        i = 0;
        while (i < BUFFER_SIZE)
        {
            write(1, &buff[i], 1);
            i++;
        }
    }
    else
        printf("ERROR\n");
    return (0);
}