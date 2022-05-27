#include "ft_printf.h"

void my_test1(int n)
{
    int i;
    i = 0;
    while (i < n)
    {
        ft_putendl_fd("blablabla", 1);
        i++;
    }
    
}