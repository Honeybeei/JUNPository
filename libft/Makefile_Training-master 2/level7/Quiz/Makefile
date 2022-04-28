NAME = main

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rc
ARC = libft.a
ARSRCS =	first.c \
			second.c \
			third.c
AROBJS = $(ARSRCS:.c=.o)

MAINSRC = main.c
MAINOBJ = $(MAINSRC:.c=.o)
INC = ./libft.h

all : $(NAME)

clean :
	rm -f $(NAME) $(MAINOBJ) $(ARC) $(AROBJS) $(ARNAME)

.PONEY : all clean


$(NAME) : $(MAINOBJ) $(ARC)
	$(CC) $(CFLAGS) $^ -o $@

$(ARC) : $(AROBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<