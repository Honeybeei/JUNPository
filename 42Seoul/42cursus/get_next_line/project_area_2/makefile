# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 17:26:11 by seoyoo            #+#    #+#              #
#    Updated: 2022/07/06 23:24:34 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# target
NAME = gnl.out

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# rules
all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) get_next_line.c get_next_line_utils.c gnl_test.c

test : all
	@./a.out
	@rm ./a.out

.PONEY: all test
