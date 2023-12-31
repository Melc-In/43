# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 23:38:02 by cglandus          #+#    #+#              #
#    Updated: 2023/12/31 12:16:54 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./libft/libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRC = push_swap.c\
	  parse.c\
	  operations.c\
	  doperations.c\
	  sortalgo.c\
	  utils.c\

SRCB = parse.c\
	   operations.c\
	   doperations.c\
	   sortalgo.c\
	   utils.c\

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

all: $(LIBFT) ${NAME}

$(NAME): ${OBJ}
	${CC} -o ${NAME} ${OBJ} ${LIBFT} ${CFLAGS}

%.o: %.c
	${CC} -o $@ -c -g $< ${CFLAGS}

$(LIBFT):
	@make -C libft

checker: $(LIBFT) ${NAME}
	${CC} -o checker checker.c -g ${OBJB} ${LIBFT} ${CFLAGS}

clean:
	rm -rf ${OBJ}
	rm -rf checker.o
	@make -C libft clean

fclean: clean
	rm -rf push_swap
	rm -rf checker
	@make -C libft fclean

re: fclean all

.PHONY: all clean libft fclean re
