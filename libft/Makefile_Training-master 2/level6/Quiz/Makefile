NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rc

SRCS =	first.c \
		second.c \
		third.c
OBJS =	$(SRCS:.c=.o)

all : $(NAME)

clean : 
	rm -f $(OBJS);

fclean : clean
	rm -f $(NAME);

re : fclean all

.POHNY : all clean fclean re

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^





