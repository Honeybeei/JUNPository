NAME = main

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
SRCS =	main.c \
		first.c \
		second.c \
		third.c
SRC = $(addprefix $(SRC_DIR), $(SRCS))

OBJ_DIR = ./obj/
OBJS = $(SRCS:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJS))

INC_DIR = ./include
INC = -I $(INC_DIR)

all : $(NAME)

clean : 
	rm -rf $(OBJ_DIR) $(NAME)

.PONEY : all clean


$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $^ -o $@