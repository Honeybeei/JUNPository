# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 01:59:59 by seoyoo            #+#    #+#              #
#    Updated: 2022/06/25 20:03:50 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# target
NAME = libftprintf.a

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# archive
AR = ar
ARFLAGS = -rcs

# include
INC_DIR = ./inc
INC = -I$(INC_DIR)

# my_lib
MY_LIB_DIR = ./my_lib/
MY_LIB_ARC = my_lib.a

# source
SRC_DIR = ./src/
SRC_FILE = \
		makefile_test1.c \
		ft_printf.c \
		fmt_list.c \
		utils.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILE))

# object
OBJ_DIR = ./obj/
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

# test
TEST_DIR = ./test/
TEST_FILES = \
		main_test.c

TEST_SRCS = $(addprefix $(TEST_DIR), $(TEST_FILES))

# rules
all : $(NAME)

bonus : all

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@make -C $(MY_LIB_DIR)
	@cp $(MY_LIB_DIR)/$(MY_LIB_ARC) .
	@mv $(MY_LIB_ARC) $(NAME)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	@make clean -C $(MY_LIB_DIR)
	@rm -rf ./obj

fclean : clean
	@rm -f $(MY_LIB_DIR)/$(MY_LIB_ARC)
	@rm -f $(NAME)

re: fclean all

test : all
	$(CC) $(CFLAGS) $(NAME) $(INC) $(TEST_SRCS)
	@./a.out
	@rm ./a.out

test_flag_off : all
	$(CC) $(NAME) $(INC) $(TEST_SRCS)
	@./a.out
	@rm ./a.out

test_without_ar :
	$(CC) $(CFLAGS) $(INC) $(TEST_SRCS)
	@./a.out
	@rm ./a.out

test_without_ar_flag_off :
	$(CC) $(INC) $(TEST_SRCS)
	@./a.out
	@rm ./a.out

.PONEY: all bonus clean fclean re test test_flag_off test_without_ar
