# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 12:22:21 by cglandus          #+#    #+#              #
#    Updated: 2023/07/14 00:25:43 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = /

NAME_SERVER = server

NAME_CLIENT = client

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRC = client.c\
	  server.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	${CC} -o $@ -c $< ${CFLAGS}

$(NAME_SERVER): ${OBJ}

all: ${NAME_SERVER} ${NAME_CLIENT}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re

