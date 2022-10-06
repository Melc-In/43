# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 18:32:12 by cglandus          #+#    #+#              #
#    Updated: 2022/10/07 00:21:24 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = atoi.c bzero.c isalnum.c isalpha.c isascii.c isdigit.c isprint.c memcmp.c memcpy.c memmove.c memset.c strchr.c strlcat.c strlcpy.c strlen.c strncmp.c strnstr.c strrchr.c tolower.c toupper.c

OBJ = $(SRC:.c=.o)

%o : %.c
	${CC} ${CFLAGS} -c -o

all: $(NAME)

$(NAME): 
	ar rc ${NAME} ${OBJ}

clean: 
	@rm ${OBJ}

fclean: clean 
	@rm ${NAME}

re: fclean all

.PHONY: all clean fclean re
