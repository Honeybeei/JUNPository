/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 02:20:21 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/10 23:32:01 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_test_utils.h"

#define FILE_COUNT 5
#define FILE1 "./text_file/file1.txt"
#define FILE2 "./text_file/file2.txt"
#define FILE3 "./text_file/file3.txt"
#define FILE4 "./text_file/file4.txt"
#define FILE5 "./text_file/file5.txt"

int main(void)
{
	int	fd[FILE_COUNT];
	char *str;

	fd[0] = open(FILE1, O_RDONLY);
	fd[1] = open(FILE2, O_RDONLY);
	fd[2] = open(FILE3, O_RDONLY);
	fd[3] = open(FILE4, O_RDONLY);
	fd[4] = open(FILE5, O_RDONLY);
	
	// while (TRUE)
	// {
		str = get_next_line(fd[4]);
		// if (str == NULL)
		// 	break;
		// else
			printf("[%s]", str);
	// }
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	close(fd[4]);
	
	return 0;
}