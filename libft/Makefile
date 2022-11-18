# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 21:05:17 by cglandus          #+#    #+#              #
#    Updated: 2022/11/18 23:25:34 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	  ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
	  ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	  ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c\
	  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
	  ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

SRCB = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
	   ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

ifdef BONUS
	SRC += ${SRCB}
endif

%.o: %.c
	@echo "\033[1;31m[Compiling...]\033[1;00m "$<
	@${CC} -o $@ -c $< ${CFLAGS}

all: ${NAME}

$(NAME): ${OBJ}
	@echo "\033[1;31m[Linking...]\033[1;00m "$@
	@ar rc ${NAME} ${OBJ}
	@ranlib ${NAME}
	@echo "\033[1;32m[Build finished]\033[1;00m"

bonus:
	@make BONUS=1 --no-print-directory

clean:
	@echo "\033[1;31m[Cleaning ...]\033[1;00m "
	@rm -rf ${OBJ} ${OBJB}

fclean: clean
	@rm -rf ${NAME}
	@echo "\033[1;32m[Cleaned]\033[1;00m "

re: fclean all

.PHONY: all clean fclean re bonus
