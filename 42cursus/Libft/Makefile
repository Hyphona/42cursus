# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alperrot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 13:15:26 by alperrot          #+#    #+#              #
#    Updated: 2023/11/18 13:48:43 by alperrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(wildcard ./*.c)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./
OFILES = $(SRC:.c=.o)
NAME = libft.a

$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)

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
