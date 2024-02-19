# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 21:05:17 by cglandus          #+#    #+#              #
#    Updated: 2024/02/19 01:31:44 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRC = ft_abs.c\
	  ft_atoi.c\
	  ft_bzero.c\
	  ft_calloc.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_itoa.c\
	  ft_join.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_printf.c\
	  ft_putchar_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_base_fd.c\
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
	  get_next_line.c\
	  ft_lstadd_back.c\
	  ft_lstadd_front.c\
	  ft_lstclear.c\
	  ft_lstdelone.c\
	  ft_lstiter.c\
	  ft_lstlast.c\
	  ft_lstmap.c\
	  ft_lstnew.c\
	  ft_lstsize.c

OBJ = $(SRC:.c=.o)

RED = \033[1;31m
PURPLE = \033[1;35m
GREEN = \033[1;32m

all: $(NAME)

%.o: %.c
	@echo "$(GREEN)[Compiling] -> $<"
	@$(CC) -o $@ -c $< $(CFLAGS)

$(NAME): $(OBJ)
	@echo "$(GREEN)[Linking] -> libft.a"
	@ar rcs $(NAME) $(OBJ)

clean:
	@echo "$(PURPLE)[Cleaning]$(RED)"
	rm -rf $(OBJ)
	@echo "$(PURPLE)[Cleaned]$(RED)"

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
