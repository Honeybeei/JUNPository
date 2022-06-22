# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 13:42:21 by seoyoo            #+#    #+#              #
#    Updated: 2022/06/21 16:52:15 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# target
NAME = my_lib.a

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# archive
AR = ar
ARFLAGS = -rcs

# include
INC_DIR = ./inc/
INC = -I $(INC_DIR)

# source
SRC_DIR = ./src/
SRC_FILES = \
		my_itoa.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

# object
OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# libft directory
LIBFT_DIR = ./libft/

# test
TEST_DIR = ./test/
TEST_FILES = \
		main_test.c

TEST_SRCS = $(addprefix $(TEST_DIR), $(TEST_FILES))

# rules
all : $(NAME)

bonus : all

$(NAME) : $(OBJS)
	@make bonus -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	@make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(LIBFT_DIR)libft.a
	rm -f $(NAME)

re: fclean all

test : all
	$(CC) $(CFLAGS) $(NAME) $(INC) $(TEST_SRCS)
	@./a.out
	@rm ./a.out

test_flag_off : all
	$(CC) $(NAME) $(INC) $(TEST_SRCS)
	@./a.out
	@rm ./a.out

.PONEY: all bonus clean fclean re
