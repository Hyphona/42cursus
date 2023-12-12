SRC	:= ./libft/ft_atoi.c ./libft/ft_bzero.c ./libft/ft_calloc.c ./libft/ft_isalnum.c ./libft/ft_isalpha.c ./libft/ft_isascii.c\
	./libft/ft_isdigit.c ./libft/ft_isprint.c ./libft/ft_itoa.c ./libft/ft_memchr.c ./libft/ft_memcmp.c\
	./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_memset.c ./libft/ft_putchar_fd.c ./libft/ft_putendl_fd.c\
	./libft/ft_putnbr_fd.c ./libft/ft_putstr_fd.c ./libft/ft_split.c ./libft/ft_strchr.c ./libft/ft_strdup.c\
	./libft/ft_striteri.c ./libft/ft_strjoin.c ./libft/ft_strlcat.c ./libft/ft_strlcpy.c ./libft/ft_strlen.c\
	./libft/ft_strmapi.c ./libft/ft_strncmp.c ./libft/ft_strnstr.c ./libft/ft_strrchr.c ./libft/ft_strtrim.c\
	./libft/ft_substr.c ./libft/ft_tolower.c ./libft/ft_toupper.c ./libft/ft_isxdigit.c ./libft/ft_isblank.c\
	./libft/ft_iscntrl.c ./libft/ft_ispunct.c ./libft/ft_isspace.c ./libft/ft_countword.c ./libft/ft_intlen.c\
	ft_printf.c
CC	:= gcc
CFLAGS	:= -Wall -Werror -Wextra -I./libft
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
