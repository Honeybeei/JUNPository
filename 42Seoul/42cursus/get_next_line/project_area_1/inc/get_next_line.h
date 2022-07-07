/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:01:32 by seoyoo            #+#    #+#             */
/*   Updated: 2022/07/05 20:38:49 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

# define BUFFER_SIZE 10  // will be compiled with -D option. now just for making

// char	*str will not be '\0' terminated. End of string is end of buffer. 
typedef struct s_string
{
	char 	*str;
	size_t	buf_size;
}	t_string;

typedef struct s_str_saver
{
	int					fd;
	t_string			*saved_str;
	struct s_str_saver	*next;
}	t_str_saver;


// get_next_line.c
char	*get_next_line(int fd);

// get_next_line_utils.c
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif