# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 14:46:26 by cglandus          #+#    #+#              #
#    Updated: 2024/03/01 00:11:51 by cglandus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = MacroLibX
MLX = $(MLX_DIR)/libmlx.so

CC = clang

CFLAGS = -Wall -Werror -Wextra -g

SRC_DIR = src
BUILD_DIR = build

SRC = so_long.c \
	  parser.c \
	  map_init.c\
	  map_check.c\
	  map_solv.c\
	  renderer.c\
	  mov.c\
	  utils.c

OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(BUILD_DIR)/, $(OBJ))
SRC := $(addprefix $(SRC_DIR)/, $(SRC))

RED = \033[1;31m
PURPLE = \033[1;35m
GREEN = \033[1;32m

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(GREEN)[Compiling] -> $<"
	@$(CC) -o $@ -c $< $(CFLAGS)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(CFLAGS) -lSDL2

$(LIBFT):
	@make -C $(LIBFT_DIR) -j

$(MLX):
	@make -C $(MLX_DIR) -j

valgrind: $(NAME)
	@valgrind -s --suppressions=MacroLibX/valgrind.supp --leak-check=full --show-leak-kinds=all ./$(NAME)

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re