/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:32:49 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/07 23:42:02 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "functions_4_test.h"
#include <stdio.h>
#include <memory.h>
#include <fcntl.h>  // open

#define FILE1 "./text_file/gnl_test1.txt"
#define FILE2 "./text_file/gnl_test2.txt"
#define FILE3 "./text_file/gnl_test3.txt"

int main(void)
{
	int fd1; 

	fd1 = open(FILE1, O_RDONLY);
	

	return (0);
}