/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:43:39 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/16 18:23:28 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
This function read format string and print it to STD output. 
*/
int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*str;
	t_fmt_nd	*head_nd;
	int			char_count;

	va_start(ap, format);
	str = (char *)format;
	if (str == NULL)
		return (0);
	head_nd = parse_string_to_list(str, ap);
	if (head_nd == NULL)
		return (-1);
	char_count = print_format_node(head_nd);
	termination_protocol(head_nd);
	return (char_count);
}

/*
This function parse format string and split it in to t_fmt_nd linked list. 
*/
t_fmt_nd	*parse_string_to_list(char *str, va_list ap)
{
	t_fmt_nd	*head;
	t_fmt_nd	*tail;

	head = NULL;
	while (*str)
	{
		if (head == NULL)
		{
			head = make_t_fmt_node();
			tail = head;
		}
		else
		{
			tail->next_ = make_t_fmt_node();
			tail = tail->next_;
		}
		if (*str == '%')
			str += parse_format_specification(str, ap, tail);
		else
			str += copy_plain_str_to_fmt_nd(str, tail);
		if(tail == NULL)
			return (termination_protocol(head));
	}
}

/*
This function make new t_fmt_node. member vbariable (spec_, str_, next_) of new 
node will be NULL initialized. 
*/
t_fmt_nd	*make_t_fmt_node(void)
{
	t_fmt_nd	*new_node;

	new_node = malloc(sizeof(t_fmt_nd));
	if (new_node == NULL)
		return (NULL);
	new_node->spec_ = NULL;
	new_node->str_ = NULL;
	new_node->next_ = NULL;
}

/*
This function erase(free) all t_fmt_nd from head to tail and return NULL when
its over.
*/
void	*termination_protocol(t_fmt_nd *head)
{
	t_fmt_nd	*del_nd;

	while (head != NULL)
	{
		del_nd = head;
		head = head->next_;
		if (del_nd->spec_ != NULL)
			free(del_nd->spec_);
		if (del_nd->str_ != NULL)
			free(del_nd->str_);
		free(del_nd);
	}
	return (NULL);
}



// /*
// This function parse format string and split it in to t_fmt_nd linked list. 
// */
// t_fmt_nd	*parse_string_to_list(char *str, va_list ap)
// {
// 	t_fmt_nd	*new_node;
// 	t_fmt_nd	*head;
// 	t_fmt_nd	*tail;

// 	head = NULL;
// 	while (*str)
// 	{
// 		if (*str == '%')
// 		{
// 			new_node = make_t_fmt_node(parse_format_spec(str, ap), NULL);
// 			str += new_node->spec_->f_spec_len;
// 		}
// 		else
// 		{
// 			new_node = make_t_fmt_node(NULL, NULL);
// 			str += read_plain_string(str, new_node->str_);
// 		}
// 		if (head == NULL)
// 		{
// 			head = new_node;
// 			tail = head;
// 		}
// 		else
// 		{
// 			tail->next_ = new_node;
// 			tail = tail->next_;
// 		}

// 	}
// }



// t_f_spec	*parse_format_spec(char *str, va_list ap)
// {

// }

// size_t	read_plain_string(char *str, char *dst)
// {

// }

// /*
// This function print out str_ from t_fmt_nd. It will read the whole linked node
// from head to end. 
// */
// int	print_format_node(t_fmt_nd *head)
// {

// }

// /*
// this function deletes(free) all node from head to end after printing out all 
// characters from t_fmt_nd.
// */
// void	*termination_protocol(t_fmt_nd *head)
// {

// }





