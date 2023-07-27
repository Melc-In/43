# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 12:22:21 by cglandus          #+#    #+#              #
#    Updated: 2023/07/27 00:37:34 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

LIB = ./libft/libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

all: libft server client

server:
	${CC} -o server.c ${LIB} ${CFLAGS}

client:
	${CC} -o client.c ${LIB} ${CFLAGS}

libft:
	@make -C libft

clean:
	@make -C libft clean

fclean: clean
	@make -C libft fclean

re: fclean all

.PHONY: all clean libft fclean re

