# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 23:38:02 by cglandus          #+#    #+#              #
#    Updated: 2023/12/11 15:50:44 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./libft/libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRC = push_swap.c\
	  parse.c\
	  operations.c\
	  utils.c

OBJ = $(SRC:.c=.o)

all: libft ${NAME}

$(NAME): ${OBJ}
	${CC} -o ${NAME} ${OBJ} ${LIBFT} ${CFLAGS}

%.o: %.c
	${CC} -o $@ -c $< ${CFLAGS}

libft:
	@make -C libft

clean:
	rm -rf ${OBJ}
	@make -C libft clean

fclean: clean
	rm -rf push_swap
	@make -C libft fclean

re: fclean all

.PHONY: all clean libft fclean re
