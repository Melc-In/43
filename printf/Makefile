# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 15:06:02 by cglandus          #+#    #+#              #
#    Updated: 2022/12/15 17:08:50 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang

SRC = ft_printf.c\
	  print_hex.c\
	  print_ints.c\
	  print_ptr.c\
	  absol.c\
	  print_uints.c

LIBFT = ft_atoi.o\
		ft_bzero.o\
		ft_calloc.o\
		ft_isalnum.o\
		ft_isalpha.o\
		ft_isascii.o\
		ft_isdigit.o\
		ft_isprint.o\
		ft_itoa.o\
		ft_memchr.o\
		ft_memcmp.o\
		ft_memcpy.o\
		ft_memmove.o\
		ft_memset.o\
		ft_putchar_fd.o\
		ft_putendl_fd.o\
		ft_putnbr_fd.o\
		ft_putnbr_base_fd.o\
		ft_putstr_fd.o\
		ft_split.o\
		ft_strchr.o\
		ft_strdup.o\
		ft_striteri.o\
		ft_strjoin.o\
		ft_strlcat.o\
		ft_strlcpy.o\
		ft_strlen.o\
		ft_strmapi.o\
		ft_strncmp.o\
		ft_strnstr.o\
		ft_strrchr.o\
		ft_strtrim.o\
		ft_substr.o\
		ft_tolower.o\
		ft_toupper.o

OBJ = $(SRC:.c=.o)

%.o: %.c
	${CC} -o $@ -c $< ${CFLAGS}

all: ${NAME}

$(NAME): ${OBJ}
	@make -C libft
	@ar -x libft/libft.a
	@ar rc ${NAME} ${OBJ} ${LIBFT}

clean:
	rm -rf ${OBJ} ${LIBFT}

fclean: clean
	rm -rf ${NAME}
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re

