#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int c;

    c = 127;
    if (isascii(c))
        printf("YESS, return value : %d", isascii(c));
    else
        printf("NOOO, return value : %d", isascii(c));

    
}