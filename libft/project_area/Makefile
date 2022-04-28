# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 13:42:21 by seoyoo            #+#    #+#              #
#    Updated: 2022/04/28 12:27:38 by seoyoo           ###   ########.fr        #
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
SRC_DIR = ./
SRCS = \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c
SRC = $(addprefix $(SRC_DIR), $(SRCS))

# bonus_source
BN_SRC_DIR = ./
BN_SRCS = 
BN_SRC = $(addprefix $(BN_SRC_DIR), $(BN_SRCS))

# object
OBJ_DIR = ./
OBJS = $(SRCS:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJS))

# bonus_object
BN_OBJ_DIR = ./
BN_OBJS = $(BN_SRCS:.c=.o)
BN_OBJ = $(addprefix $(BN_OBJ_DIR), $(BN_OBJS))


# rules
all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

bonus : $(OBJ) $(BN_OBJ)
	$(AR) $(ARFLAGS) $(NAME) $^

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $^

$(BN_OBJ) : $(BN_SRC)
	$(CC) $(CFLAGS) -c $^

clean :
	rm -f $(OBJ) $(BN_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all


