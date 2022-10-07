# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 18:32:12 by cglandus          #+#    #+#              #
#    Updated: 2022/10/07 04:20:28 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	ft_isdigit.c ft_isprint.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
	ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c\
	ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c

OBJ = $(SRC:.c=.o)

%.o : %.c
	${CC} -o $@ -c $< ${CFLAGS}

all: $(NAME)

$(NAME): ${OBJ}
	ar rc ${NAME} ${OBJ}

clean: 
	rm ${OBJ}

fclean: clean 
	rm ${NAME}

re: fclean all

.PHONY: all clean fclean re
