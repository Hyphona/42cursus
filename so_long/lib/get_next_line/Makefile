SRC	:=  ./get_next_line.c\
		./get_next_line_utils.c
CC	:= cc
CFLAGS	:= -Wall -Werror -Wextra -I./
OFILES	:= $(SRC:.c=.o)
NAME	:= gnl.a

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