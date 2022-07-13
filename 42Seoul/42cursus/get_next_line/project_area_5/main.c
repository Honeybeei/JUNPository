#include <stdio.h>
#include "src/get_next_line.h"
#include "src/get_next_line_test_utils.h"
#include <fcntl.h>  // open()

#define FILE_COUNT 3

#define FILE1 "text_files/file1.txt"
#define FILE2 "text_files/file2.txt"
#define FILE3 "text_files/file3.txt"

int main(void)
{
    int fd[FILE_COUNT];

    // fd[0] = open(FILE1, O_RDWR);
    fd[1] = open(FILE2, O_RDWR);
    // fd[2] = open(FILE3, O_RDWR);

    for (size_t i = 0; i < 20; i++)
    {
        printf("\n\n-- GNL RESULT : [%s] --\n\n", get_next_line(fd[1]));
    }
    


    // i = 0;
    // for (size_t j = 0; j < 10; j++)
    // {
    //     printf("fd : %d\n", i + 1);
    //     str = get_next_line(fd[i]);
    //     if (str == NULL)
    //         printf("ERROR or EOF\n");
    //     else
    //         printf("RESULT : [%s]\n\n", str);
    //     i++;
    //     if (i >= FILE_COUNT)
    //         i = 0;
    // }
    // close(fd[0]);
    close(fd[1]);
    // close(fd[2]);
    return 0;
}