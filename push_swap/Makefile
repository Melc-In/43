# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 23:38:02 by cglandus          #+#    #+#              #
#    Updated: 2023/12/31 14:47:34 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

LIBFT = ./libft/libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRC = push_swap.c\
	  parse.c\
	  operations.c\
	  doperations.c\
	  sortalgo.c\
	  utils.c\

SRCB = checker.c\
		parse.c\
		operations.c\
		doperations.c\
		sortalgo.c\
		utils.c\

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

all: libft ${NAME}

bonus: libft $(BONUS)

%.o: %.c
	${CC} -o $@ -c -g $< ${CFLAGS}

$(NAME): ${OBJ}
	${CC} -o ${NAME} ${OBJ} ${LIBFT} ${CFLAGS}

$(BONUS): ${OBJB}
	${CC} -o $(BONUS) -g ${OBJB} ${LIBFT} ${CFLAGS}

libft:
	@make -C libft --no-print-directory

clean:
	rm -rf ${OBJ}
	rm -rf $(OBJB)
	@make -C libft clean

fclean: clean
	rm -rf ${NAME}
	rm -rf $(BONUS)
	@make -C libft fclean

re: fclean all

.PHONY: all clean libft fclean re bonus
