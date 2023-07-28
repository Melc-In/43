# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 12:22:21 by cglandus          #+#    #+#              #
#    Updated: 2023/07/28 06:49:02 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

LIB = ./libft/libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

all: libft ${NAME}

$(NAME): server client

server:
	${CC} -o server server.c ${LIB} ${CFLAGS}

client:
	${CC} -o client client.c ${LIB} ${CFLAGS}

libft:
	@make -C libft

clean:
	@make -C libft clean

fclean:
	rm -rf client server
	@make -C libft fclean

re: fclean all

.PHONY: all clean libft fclean re

