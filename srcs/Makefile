NAME = so_long

LIBFT = libft.a

SRCS =	$(wildcard *.c)
OBJS :=$(SRCS:.c=.o)
MLX = ../miniLBX/libmlx.a

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

.PHONY: all tester clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	@make -C ../libft
	@mv ../libft/libft.a .
	@cc $(CFLAGS) -I ../miniLBX -L ../miniLBX -lmlx -framework OpenGL -framework AppKit -L /opt/X11/lib -lmlx -lXext -lX11 \
	-I/usr/local/include -L/usr/local/lib -lpng -L. $(LIBFT) $(SRCS) -o $(NAME)

tester: $(SRCS)
	@cc -Wall -Wextra -Werror -I ./miniLBX -L ./miniLBX -lmlx -framework OpenGL -framework AppKit -L /opt/X11/lib -lmlx -lXext -lX11 \
	-I/usr/local/include -L/usr/local/lib -lpng $(SRCS) -o so_long
	@./so_long
	@make fclean
clean:
	@make clean -C ../libft
	@rm -f $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
