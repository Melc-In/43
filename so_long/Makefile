# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 14:46:26 by cglandus          #+#    #+#              #
#    Updated: 2024/02/13 21:41:13 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIB = ./libft/libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRC = so_long.c\
	  parser.c\

OBJ = $(SRC:.c=.o)

RED = \033[1;31m
PURPLE = \033[1;35m
GREEN = \033[1;32m

all: libft $(NAME)

$(NAME):
	$(CC) -o so_long so_long.c $(LIB) $(CFLAGS)

libft:
	@make -C src/libft

clean:
	@make -C src/libft clean

fclean:
	@make -C src/libft fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re