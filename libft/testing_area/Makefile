TARGET = libft.a
CC = gcc
CFLAG = -Wall -Wextra -Werror

SRC_DIR = ./src/
SRC_NAME = *.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJS = $(SRCS:.c=.o)

INC_HED = -I ./includes/
LIB = ar crs

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(LIB) $(TARGET) $(OBJS)

.c.o : 
	$(CC) $(CFLAG) $(INC_HED) -c $< -o $(<:.c=.o)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY : all clean fclean re .c.o