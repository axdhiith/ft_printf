NAME=libftprintf.a

SRCS= ft_printf.c ft_printf_funcs.c
OBJS=$(SRCS:.c=.o)


CC=gcc
CFLAGS=-Wall -Wextra -Werror

# $@ - target
# $^ - butun dependen
# $< - ilk dependen

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs ${NAME} $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all