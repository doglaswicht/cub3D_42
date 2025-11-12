NAME    = cub3d

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# préprocesseur (headers) : inclure le répertoire include et mlx
CPPFLAGS = -I$(INCDIR) $(MLX_INC) -Ilibft

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)
MLX_LNK = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCDIR  = include
SRCDIR  = src
OBJ_DIR = obj

SRC = $(wildcard src/core/*.c) \
	$(wildcard src/game/*.c) \
	$(wildcard src/mlx/*.c) \
	$(wildcard src/parser/*.c) \
	$(wildcard src/player/*.c) \
	$(wildcard src/render/*.c) \
	$(wildcard src/textures/*.c) \
	$(wildcard src/utils/*.c)

# Place object files in obj/... preserving subdirectories from src/
OBJ     = $(patsubst $(SRCDIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Compilation des .c en .o en écrivant les .o dans $(OBJ_DIR)
$(OBJ_DIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all: $(MLX_LIB) libft/libft.a $(NAME)
libft/libft.a:
	@$(MAKE) -C libft

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a $(MLX_LNK) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
