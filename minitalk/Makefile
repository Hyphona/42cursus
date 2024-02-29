SRC_CLIENT		:=  client.c
SRC_SERVER		:=  server.c
OFILES_CLIENT	:= $(SRC_CLIENT:.c=.o)
OFILES_SERVER	:= $(SRC_SERVER:.c=.o)
NAME_CLIENT		:= client
NAME_SERVER		:= server
PRINTF			:= ft_printf/libftprintf.a
CC				:= cc
CFLAGS			:= -Wall -Werror -Wextra

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OFILES_CLIENT)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OFILES_CLIENT) $(PRINTF) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OFILES_SERVER)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OFILES_SERVER) $(PRINTF) -o $(NAME_SERVER)

clean:
	@make -C ft_printf clean
	rm -f $(OFILES_CLIENT)
	rm -f $(OFILES_SERVER)

fclean: clean
	@make -C ft_printf fclean
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_SERVER)

re: fclean all

.PHONY:
	all
	clean
	fclean
	re
