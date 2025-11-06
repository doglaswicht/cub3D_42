# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 10:24:38 by dleite-b          #+#    #+#              #
#    Updated: 2025/11/05 16:11:08 by csturny          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
CC			= cc
MLX_DIR		= mlx
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
CFLAGS		= -Wall -Wextra -Werror -Iinclude -I$(MLX_DIR)
RM			= rm -f

SRC_DIR		= src
OBJ_DIR		= obj

SRC			= $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT		= libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "cub3D compiled!"

$(LIBFT):
	@$(MAKE) -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C libft
	@$(RM) -r $(OBJ_DIR)
	@echo "Objects removed."

fclean: clean
	@$(MAKE) fclean -C libft
	@$(RM) $(NAME)
	@echo "Binaire removed."

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
