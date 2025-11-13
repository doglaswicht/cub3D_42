#include "cub3d.h"

int	game_init(t_game *g, const char *map_path)
{
	g->world.floor_color = -1;
	g->world.ceiling_color = -1;
	g->world.paths.no = NULL;

	g->mlx = NULL;
	g->win = NULL;
	if (!map_path || *map_path == '\0')
		return (print_error("Missing map path"));

	/* 1) Parse .cub e preencher g->world (mapa, caminhos, spawn) */
	if (parse_cub((char *)map_path, g) != 0)
		return (1);

	/* 2) Validar/copiar o spawn para o jogador corrente */
	if (init_player_from_spawn(g) != 0)
		return (1);

	/* 3) Inicializar MLX e o frame buffer */
	if (init_mlx(g) != 0)
		return (1);
	if (init_images(g) != 0)
		return (1);

	/* 4) Carregar texturas reais usando os caminhos vindos do parser */
	if (init_textures_from_paths(g) != 0)
		return (1);

	return (0);
}
