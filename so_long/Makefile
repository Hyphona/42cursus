NAME	:= so_long
SRC		:= 	hook.c\
			level.c\
			loader.c\
			main.c
OFILES	:= $(SRC:.c=.o)
PRINTF	:= lib/ft_printf/libftprintf.a
LIBMLX	:= ./lib/MLX42
MLX		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OFILES)
	@make -C lib/ft_printf
	$(CC) $(CFLAGS) $(OFILES) $(PRINTF) $(MLX) -I./include -lXext -lX11 -lm -lz -o $(NAME)

$(MLX):
	@make -s -C lib/minilibx-linux

clean:
	@make -C lib/ft_printf clean
	rm -f $(OFILES)

fclean: clean
	@make -C lib/ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
