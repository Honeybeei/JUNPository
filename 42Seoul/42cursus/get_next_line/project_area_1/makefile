# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 17:26:11 by seoyoo            #+#    #+#              #
#    Updated: 2022/07/04 23:21:40 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# target
NAME = gnl.a

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# archive
AR = ar
ARFLAGS = -rcs

# include
INC_DIR = ./inc
INC = -I$(INC_DIR)

# source
SRC_DIR = ./src/
SRC_FILE = \
		get_next_line_utils.c \
		get_next_line.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILE))

# object
OBJ_DIR = ./obj/
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

# test
TEST_DIR = ./test/
TEST_FILES = \
		gnl_test.c

TEST_SRCS = $(addprefix $(TEST_DIR), $(TEST_FILES))

# rules
all : $(NAME)

bonus : all

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	@rm -rf ./obj

fclean : clean
	@rm -f $(NAME)

re: fclean all

test : all
	$(CC) $(CFLAGS) $(NAME) $(INC) $(TEST_SRCS)
	@./a.out
	@rm ./a.out

.PONEY: all bonus clean fclean re test
