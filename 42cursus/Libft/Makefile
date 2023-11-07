# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alperrot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 13:15:26 by alperrot          #+#    #+#              #
#    Updated: 2023/11/07 20:43:27 by alperrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(wildcard ./*.c)
CFLAGS += -Wall -Werror -Wextra -I -g
OBJ = $(SRC:.c=.o)
NAME = libft

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

all:
	$(NAME)

clean:
	rm $(OBJ)

fclean:
	rm -f $(NAME)

re:
	fclean all

.PHONY:
	all
	clean
	fclean
	re
