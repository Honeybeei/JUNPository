/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:15:35 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/15 17:09:34 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>  // open()
#include "test.h"

#define FILE_COUNT 2
#define FILE1 "./test1.txt"
#define FILE2 "./test2.txt"

int main(void)
{
    int fd[FILE_COUNT];

    fd[0] = open(FILE1, O_RDONLY);
    fd[1] = open(FILE2, O_RDONLY);

    printf("%s", get_next_line(fd[0]));
    printf("%s", get_next_line(fd[1]));
    printf("%s", get_next_line(fd[0]));
    printf("%s", get_next_line(fd[1]));
    printf("%s", get_next_line(fd[0]));
    printf("%s", get_next_line(fd[1]));
    printf("%s", get_next_line(fd[0]));
    printf("%s", get_next_line(fd[1]));
    printf("%s", get_next_line(fd[0]));
    printf("%s", get_next_line(fd[1]));
    printf("%s", get_next_line(fd[0]));
    printf("%s", get_next_line(fd[1]));
    printf("%s", get_next_line(fd[0]));
    printf("%s", get_next_line(fd[1]));
    printf("%s", get_next_line(fd[0]));
    printf("%s", get_next_line(fd[1]));
    printf("%s", get_next_line(fd[0]));
    printf("%s", get_next_line(fd[1]));
    printf("%s", get_next_line(fd[0]));
    printf("%s", get_next_line(fd[1]));
    printf("%s", get_next_line(fd[0]));
    return 0;
}