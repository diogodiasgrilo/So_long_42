NAME = so_long.a

SRCS =	$(wildcard *.c)
OBJS :=$(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY: all tester clean fclean re

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

tester: $(SRCS)
	cc $(CFLAGS) $(SRCS)
	./a.out
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
