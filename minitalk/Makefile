# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 12:22:21 by cglandus          #+#    #+#              #
#    Updated: 2023/07/19 21:11:20 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ./libft

NAME_SERVER = server

NAME_CLIENT = client

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRC = client.c\
	  server.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	make -C $(LIBFT_DIR)
	${CC} -o $@ -c $< ${CFLAGS}

$(NAME_SERVER): ${OBJ}

$(NAME_CLIENT): ${OBJ}

all: ${NAME_CLIENT} ${NAME_SERVER}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re

