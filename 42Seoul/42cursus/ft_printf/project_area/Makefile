# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 01:59:59 by seoyoo            #+#    #+#              #
#    Updated: 2022/05/27 14:18:41 by seoyoo           ###   ########.fr        #
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

# libft
LIBFT_DIR = ./libft/

# source
SRC_DIR = ./src/mandatory/
SRC_FILE = \
		my_test0.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILE))

# bonus_source
BN_SRC_DIR = ./src/bonus/
BN_SRC_FILE = \
		my_test1.c

BN_SRCS = $(addprefix $(BN_SRC_DIR), $(BN_SRC_FILE))

# object
OBJ_DIR = ./obj/mandatory/
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

# bonus_object
BN_OBJ_DIR = ./obj/bonus/
BN_OBJ_FILE = $(BN_SRC_FILE:.c=.o)
BN_OBJS = $(addprefix $(BN_OBJ_DIR), $(BN_OBJ_FILE))

# add bonus
ifdef SHOW_ME_THE_BONUS1
	OBJS += $(BN_OBJS)
endif


# rules
all: $(NAME)

bonus:
	SHOW_ME_THE_BONUS1=1 make

$(NAME) : $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BN_OBJ_DIR)%.o : $(BN_SRC_DIR)%.c
	@mkdir -p $(BN_OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make fclean -C $(LIBFT_DIR)
	@rm -rf ./obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: bonus
	$(CC) $(CFLAGS) $(NAME) $(INC) my_test.c
	@./a.out
	@ rm ./a.out

.PONEY: all bonus clean fclean re test
