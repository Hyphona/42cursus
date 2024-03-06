SRC	:=  ./libft/ft_isalnum.c ./libft/ft_isalpha.c ./libft/ft_isdigit.c\
	./libft/ft_putchar_fd.c ./libft/ft_putnbr_fd.c ./libft/ft_putstr_fd.c\
	./libft/ft_strlen.c ./libft/ft_putbase_fd.c ./libft/ft_check_base.c ft_printf.c
CC	:= cc
CFLAGS	:= -Wall -Werror -Wextra -g
OFILES	:= $(SRC:.c=.o)
NAME	:= libftprintf.a

$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all
	clean
	fclean
	re
