# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 23:38:02 by cglandus          #+#    #+#              #
#    Updated: 2023/08/04 06:18:51 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./libft/libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRC = push_swap.c\
	  parse.c\
	  operations.c

OBJ = $(SRC:.c=.o)

all: libft ${NAME}

$(NAME): ${OBJ}
	${CC} -o ${NAME} ${LIBFT} ${OBJ} ${CFAGS}

%.o: %.c
	${CC} -o $@ -c $< ${CFLAGS}

libft:
	@make -C libft

clean:
	rm -rf ${OBJ}
	@make -C libft clean

fclean:
	rm -rf push_swap
	@make -C libft fclean

re: fclean all

.PHONY: all clean libft fclean re
