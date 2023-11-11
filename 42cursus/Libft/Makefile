# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alperrot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 13:15:26 by alperrot          #+#    #+#              #
#    Updated: 2023/11/11 15:22:44 by alperrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(wildcard ./*.c)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./
OFILES = $(SRC:.c=.o)
NAME = libft.a

$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OFILES)

all:
	$(NAME)

clean:
	rm -f $(OFILES)

fclean: 
	clean
	rm -f $(NAME)

re:
	fclean all

.PHONY:
	all
	clean
	fclean
	re
