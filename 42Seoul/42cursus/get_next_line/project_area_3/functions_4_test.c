#include "get_next_line.h"


/*
function for test new_buf_node()
*/
void	print_buffer_info(t_buf *buff_node)
{
	if (buff_node == NULL)
	{
		printf("NULL\n");
		return;
	}
	printf("current buffer : [%p]", buff_node);
	if (buff_node->eof == true)
		printf(" -  EOF\n");
	else
		printf(" - !EOF\n");
	for (size_t i = 0; i < BUFFER_SIZE + 10; i++)
	{
		if (buff_node->buf[i] == '\n')
			printf("[%4s]", "\\n");
		else if (buff_node->buf[i] == 0)
			printf("[%4s]", "\\0");
		else
			printf("[%4c]", buff_node->buf[i]);
	}
	printf("\n\n");
}

