all: client.o server.o
	@make -C ft_printf
	cc -Wall -Werror -Wextra -I./ -o client client.o ft_printf/libftprintf.a
	cc -Wall -Werror -Wextra -I./ -o server server.o ft_printf/libftprintf.a

clean:
	@make -C ft_printf clean
	rm -f client.o server.o

fclean: clean
	@make -C ft_printf fclean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re
