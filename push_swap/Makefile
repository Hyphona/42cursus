SRC	:= 	./operations/push.c\
		./operations/rev_rotate.c\
		./operations/rotate.c\
		./operations/swap.c\
		./sort/algorithm.c\
		./sort/utils.c\
		./utils/main_utils.c\
		./utils/node_utils.c\
		./utils/parser_utils.c\
		./utils/stack_utils.c\
		main.c\
		parser.c

CC	:= gcc
CFLAGS	:= -Wall -Werror -Wextra -I./includes -g
OFILES	:= $(SRC:.c=.o)
NAME	:= push_swap

$(NAME): $(OFILES)
	${CC} ${CFLAGS} ${OFILES} -o ${NAME}

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