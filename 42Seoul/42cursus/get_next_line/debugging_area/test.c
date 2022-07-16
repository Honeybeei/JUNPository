#include "get_next_line.h"
#include "test.h"

void	print_b_node(t_b_node *b_node)
{
	printf("[B_NODE]\n");
	printf("Node address : %p\n", b_node);
	printf("Start : %zd\n", b_node->start);
	printf("End   : %zd\n", b_node->end);
	printf("RDCNT : %zd\n", b_node->read_cnt);
	printf(" - BUFFERS - \n");
	for (size_t i = 0; i < BUFFER_SIZE; i++)
	{
		if (b_node->buffer[i] == '\n')
			printf("[\\n ]");
		else
			printf("[ %c ]", b_node->buffer[i]);
	}
	printf("\n\n");
}