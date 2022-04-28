NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rc

SRCS = first.c \
	second.c \
	third.c
OBJS = $(SRCS:.c=.o)


$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJS) : $(SRCS)
