#include <stdio.h>


size_t	get_buff_size(int n)
{
	size_t	buff_size;

	buff_size = 2;
	if (n < 0)
		buff_size++;
	while (1)
	{
		n /= 10;
		if (n == 0)
			return (buff_size);
		buff_size++;
	}
}
