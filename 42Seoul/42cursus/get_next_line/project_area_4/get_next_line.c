/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:32:10 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/10 23:17:04 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>  // TODO : erase this
#include "get_next_line_test_utils.h"  // TODO : erase this

char    *get_next_line(int fd)
{
	static t_h_ptr	*head_ptr_list = NULL;
	t_h_ptr			*head_ptr;
	char			*str;
	size_t			char_count;

	head_ptr = search_matching_fd(fd, head_ptr_list);
	char_count = count_char(head_ptr);
	printf("char count : %lu\n", char_count);  // TODO : erase this
	str = malloc(sizeof(char) * (char_count + 1));
	if (str == NULL)
		return (NULL);
	str[char_count] = '\0';
	printf("print node to eof start\n");  // TODO : erase this
	print_node_to_eof(head_ptr);  // TODO : erase this
	printf("print node to eof end\n");  // TODO : erase this
	copy_char_from_buf_to_str(head_ptr, str);
	termination_protocol(head_ptr);
	return (str);
}

/*
This function returns a head node pointer that matches the file descriptor. If 
there is no node matching the file descriptor, a new head node pointer will be 
created and it will point the new head node.
*/
t_h_ptr *search_matching_fd(int fd, t_h_ptr *head_ptr_list)
{
	while (TRUE)
	{
		if (head_ptr_list == NULL)
		{
			head_ptr_list = malloc(sizeof(t_h_ptr));
			if (head_ptr_list == NULL)
				return (NULL);
			head_ptr_list->fd = fd;
			head_ptr_list->head = new_buf_node(fd);
			if (head_ptr_list->head == NULL)
				return (NULL);
			head_ptr_list->next = NULL;
		}
		else
		{
			if (head_ptr_list->fd == fd)
				return (head_ptr_list);
			else
				head_ptr_list = head_ptr_list->next;
		}
	}
}


/*
This function returns a new buffer node. Buffer will be filled by a read() 
function. Start pointer will be initialized by pointing the first character of 
the buffer node and end pointer will be initialized by pointing first occuring 
new line character or the last character of file. If new line character or the 
last character of file is not in buffer, end pointer will point NULL; 
*/
t_b_node    *new_buf_node(int fd)
{
	t_b_node    *node;

	node = malloc(sizeof(t_b_node));
	if (node == NULL)
		return (NULL);
	node->read_count = read(fd, node->buffer, BUFFER_SIZE);
	if (node->read_count <= 0)
		return (NULL);
	node->start = node->buffer;
	node->end = ft_memchr(node->start, '\n', node->read_count);
	if (node->read_count < BUFFER_SIZE && node->end == NULL)
		node->end = node->buffer + node->read_count - 1;
	return (node);
}

/*
This function returns char count from start(t_b_node->start) to end(t_b_node->
end). If end pointer is null, it means there is no next line character or the 
last character of file. Therefore, skip to next buffer node and search for end 
pointer. 
*/
size_t	count_char(t_h_ptr *head_ptr)
{
	t_b_node	*head;
	size_t		count;

	head = head_ptr->head;
	count = 0;
	while (TRUE)
	{
		if (head->end == NULL)
		{
			count += BUFFER_SIZE - (head->start - head->buffer);
			head->next = new_buf_node(head_ptr->fd);
			head = head->next;
		}
		else
		{
			count += head->end - head->start + 1;
			return (count);
		}
	}
}

/*
This function copies char data from buf_node's buffer to string.
*/
void	copy_char_from_buf_to_str(t_h_ptr *head_ptr, char *str)
{
	t_b_node	*head;
	size_t		count;

	head = head_ptr->head;
	while (TRUE)
	{
		if (head->end == NULL)
		{
			printf("copying buffer without end\n");  // TODO : erase this
			count = BUFFER_SIZE - (head->start - head->buffer);
			str = ft_memcpy(str, head->start, count) + count;
			head = head->next;
		}
		else
		{
			printf("copying buffer with end\n");  // TODO : erase this
			count = head->end - head->start + 1;
			ft_memcpy(str, head->start, count);
			return ;
		}
	}
}

/*
This function erases nodes from head to the tail's previous node. If end pointer
is pointing the last character of the buffer, make new node and set it as the 
tail node. And relocate two (start, end) pointer of tail's node. Finally set 
head_ptr->head to point the tail node.
*/
void	termination_protocol(t_h_ptr *head_ptr)
{
	t_b_node	*tail;
	t_b_node	*del_node;
	size_t		search_range;

	tail = head_ptr->head;
	while (tail->next != NULL)
	{
		del_node = tail;
		tail = tail->next;
		free(del_node);
	}
	if (tail->end == tail->buffer + BUFFER_SIZE - 1)
	{
		tail->next = new_buf_node(head_ptr->fd);
		del_node = tail;
		tail = tail->next;
		free(del_node);
	}
	else
	{
		tail->start = tail->end;
		search_range = tail->read_count - (tail->start - tail->buffer);
		tail->end = ft_memchr(tail->start, '\n', search_range);
	}
	head_ptr->head = tail;
}