# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 15:06:02 by cglandus          #+#    #+#              #
#    Updated: 2022/12/20 22:50:43 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang

SRC = absol.c\
	  ft_bzero.c\
	  ft_printf.c\
	  ft_putchar_fd.c\
	  ft_putnbr_base_fd.c\
	  ft_putnbr_fd.c\
	  ft_putstr_fd.c\
	  print_hex.c\
	  print_ints.c\
	  print_ptr.c\
	  print_uints.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	${CC} -o $@ -c $< ${CFLAGS}

all: ${NAME}

$(NAME): ${OBJ}
	@ar rc ${NAME} ${OBJ}
	@ranlib ${NAME}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re

