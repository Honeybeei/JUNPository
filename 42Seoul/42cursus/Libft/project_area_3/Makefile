# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 13:42:21 by seoyoo            #+#    #+#              #
#    Updated: 2022/05/25 18:38:10 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# target
NAME = libft.a

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# archive
AR = ar
ARFLAGS = -rcs

# include
INC_DIR = ./
INC = -I $(INC_DIR)

# source
SRC_DIR = ./src/mandatory/
SRC_FILE = \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILE))

# bonus_source
BN_SRC_DIR = ./src/bonus/
BN_SRC_FILE = \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

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
ifdef SHOW_ME_THE_BONUS
	OBJS += $(BN_OBJS)
endif

# rules
all: $(NAME)

bonus:
	SHOW_ME_THE_BONUS=1 make

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BN_OBJ_DIR)%.o : $(BN_SRC_DIR)%.c
	@mkdir -p $(BN_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf ./obj
	# rm -rf $(OBJ_DIR) $(BN_OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: bonus
	$(CC) $(CFLAGS) $(NAME) my_test.c
	@./a.out
	@ rm ./a.out

.PONEY: all bonus clean fclean re
