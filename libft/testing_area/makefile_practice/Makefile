# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo < seoyoo@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 20:18:45 by seoyoo            #+#    #+#              #
#    Updated: 2022/04/21 16:48:44 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# .SUFFIXES : .c .o
NAME = a.out
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = ./
SRCS = main.c \
	first.c \
	second.c
OBJECTS = $(SRCS:.c=.o)
INC = ./main.h

$(NAME) : $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS)

$(OBJECTS) : $(INC) $(SRCS)

# main.o : main.c
# 	gcc -c main.c

# first.o : first.c
# 	gcc -c first.c

# second.o : second.c
# 	gcc -c second.c

clean : 
	rm $(OBJECTS) $(NAME)