# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 17:26:11 by seoyoo            #+#    #+#              #
#    Updated: 2022/07/07 22:06:26 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# target
NAME = gnl.out

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# rules
all : $(NAME)
	@./a.out
	@rm ./a.out

$(NAME) :
	$(CC) $(CFLAGS) get_next_line.c get_next_line_utils.c functions_4_test.c main.c

.PONEY: all
