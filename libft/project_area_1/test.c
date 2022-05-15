#include <stdio.h>
#include <string.h>  // strnstr
#include <stdlib.h>  // atoi
#include "libft.h"

int main(void)
{
    printf("\n\n\t\t[ T E S T ]\n\n");

    printf("\t[strlcpy testing]\n\n");
    char *src = "WAAA hello world!!";
    char *dst = "hello";
    size_t dst_size = 10;
    strlcpy(dst, src, dst_size);
    printf("src [%s]\n", src);
    printf("dst [%s]\n", dst);
    
    return 0;
}
