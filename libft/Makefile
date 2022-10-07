# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 18:32:12 by cglandus          #+#    #+#              #
#    Updated: 2022/10/07 02:35:04 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = atoi.c bzero.c calloc.c isalnum.c isalpha.c isascii.c\
	isdigit.c isprint.c memcmp.c memcpy.c memmove.c memset.c\
	strchr.c strdup.c strlcat.c strlcpy.c strlen.c strncmp.c\
	strnstr.c strrchr.c tolower.c toupper.c

OBJ = $(SRC:.c=.o)

%.o : %.c
	${CC} -o $@ -c $< ${CFLAGS}

all: $(NAME)

$(NAME): ${OBJ}
	ar rc ${NAME} ${OBJ}

clean: 
	@rm ${OBJ}

fclean: clean 
	@rm ${NAME}

re: fclean all

.PHONY: all clean fclean re
