NAME = so_long

SRCS =	$(wildcard ./srcs/*.c)

OBJS :=$(SRCS:.c=.o)

LIBFTA	= ./libft/libft.a

MLX	= ./miniLBX/libmlx.a

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

MLX_FLAGS	= -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME):  $(MLX) $(LIBFTA) $(OBJS)
	@cc $(CFLAGS) $(OBJS) $(MLX) $(LIBFTA) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)Successfully built --> $(YELLOW)$(NAME)$(DEFAULT)"

$(LIBFTA):
	@make -C libft

$(MLX):
	@make -C mlx

clean:
	@make fclean -C ./libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) libft.a
	@echo "$(GREEN)Successfully cleaned --> $(YELLOW)$(NAME)$(DEFAULT)"

re: fclean all

.PHONY: all tester clean fclean re

#COLORS
GREEN = \033[1;32m
RED = \033[1;31m
DEFAULT = \033[0m
YELLOW = \033[1;33m
