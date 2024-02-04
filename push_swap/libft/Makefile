# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 21:05:17 by cglandus          #+#    #+#              #
#    Updated: 2024/02/04 01:28:59 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra -DBUFFER_SIZE=1

SRC = ft_atoi.c\
	  ft_bzero.c\
	  ft_calloc.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_itoa.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_putchar_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\
	  ft_putstr_fd.c\
	  ft_split.c\
	  ft_strchr.c\
	  ft_strdup.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlcpy.c\
	  ft_strlen.c\
	  ft_strmapi.c\
	  ft_strncmp.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strtrim.c\
	  ft_substr.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  get_next_line_utils.c\
	  get_next_line.c

SRCB = ft_lstadd_back.c\
	   ft_lstadd_front.c\
	   ft_lstclear.c\
	   ft_lstdelone.c\
	   ft_lstiter.c\
	   ft_lstlast.c\
	   ft_lstmap.c\
	   ft_lstnew.c\
	   ft_lstsize.c

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

ifdef BONUS
	SRC += ${SRCB}
endif

%.o: %.c
	${CC} -o $@ -c $< ${CFLAGS}

all: ${NAME}

$(NAME): ${OBJ}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

bonus:
	@make BONUS=1 --no-print-directory

clean:
	rm -rf ${OBJ} ${OBJB}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
