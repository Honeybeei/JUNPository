# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 20:39:01 by seoyoo            #+#    #+#              #
#    Updated: 2022/07/15 18:02:52 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# target
NAME = a.out

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# source
SRC_DIR = ./
SRC_FILE = \
		get_next_line.c \
		get_next_line_utils.c \
		main.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILE))

# rules
all : $(NAME)

bonus : all

$(NAME) :
	$(CC) $(CFLAGS) -g3 $(SRCS)

clean :
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM

re: clean all

.PONEY: all clean re