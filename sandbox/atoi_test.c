#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("%d\n", atoi("2147483647"));

    printf("\n--------------\n\n");
    printf("%d %d %d %d %d %d\n", '\t', '\n', '\v', '\f', '\r', ' ');
    return 0;
}