#include <stdio.h>
#include <ctype.h>
#include <string.h>

unsigned long int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

int main(void)
{
    int c;
    int result;
    
    c = 100;
    result = isprint(c);
    if (result)
        printf("YESS, return value : %d\n", result);
    else
        printf("NOOO, return value : %d\n", result);

    const char *str = "Hello world!";

    printf("%lu\n", ft_strlen(str));
    printf("%lu\n", strlen(str));

    
}