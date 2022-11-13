# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 18:32:12 by cglandus          #+#    #+#              #
#    Updated: 2022/11/11 15:53:12 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
    ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
    ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
    ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c\
    ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c\
    ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

SRCB = ft_lstnew.c

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

%.o : %.c
    ${CC} -o $@ -c $< ${CFLAGS}

all: ${NAME}

$(NAME): ${OBJ}
    ar rc ${NAME} ${OBJ}
    ranlib ${NAME}

so:
    $(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(SRCB)
    gcc -nostartfiles -shared -o libft.so $(OBJ) $(OBJB)

bonus:
    ar rc $ aller...

clean: 
    rm -rf ${OBJ} ${OBJB}

fclean: clean
    rm -rf ${NAME}

re: fclean all

reb: fclean bonus

.PHONY: all clean fclean re so bonus
