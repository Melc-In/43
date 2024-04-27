# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/31 22:59:01 by cglandus          #+#    #+#              #
#    Updated: 2024/04/26 22:09:52 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = clang

CFLAGS = -Wall -Werror -Wextra -g

SRC_DIR = src
BUILD_DIR = build

SRC = philo.c\
	  philo_utils.c\
	  parse.c\
	  simmulation.c

OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(BUILD_DIR)/, $(OBJ))
SRC := $(addprefix $(SRC_DIR)/, $(SRC))

GREEN = \033[1;32m

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@echo "$(GREEN)[Compiling] -> $<"
	@$(CC) -o $@ -c $< $(CFLAGS)


$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re
