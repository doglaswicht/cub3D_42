#include "cub3d.h"

/*
int	game_init(t_game *g, const char *map_path)
{
	g->mlx = NULL;
	g->win = NULL;

	// 1) Charger la map (temporaire : version simple)
	if (load_map_simple(&g->world, map_path) != 0)
	{
		write(2, "Error: failed to load map\n", 26);
		return (1);
	}

	// debug print
	print_map(&g->world);   // 👈 affiche la map chargée
	// 2) Initialiser le joueur (caméra)
	player_init(g);

	// 3) Initialisation MLX
	if (init_mlx(g) != 0)
		return (1);
	if (init_images(g) != 0)
		return (1);

	return (0);
}
*/

// version hardcode_world
int	game_init(t_game *g, const char *map_path)
{
	g->mlx = NULL;
	g->win = NULL;
	(void)map_path;

	// 1) Remplir le monde (temporaire)
	if (hardcode_world(&g->world) != 0)
	{
		write(2, "Error: failed to hardcode world\n", 33);
		return (1);
	}

	print_map(&g->world);  // pour debug
	print_world_debug(&g->world);

	// 2) Copier le spawn dans le joueur courant
	g->player = g->world.spawn;

	// 3) Initialisation MLX
	if (init_mlx(g) != 0)
		return (1);
	if (init_images(g) != 0)
		return (1);

	return (0);
}


void	game_destroy(t_game *g)
{
	// détruire l’image frame si tu en as une
	if (g->frame.img)
		mlx_destroy_image(g->mlx, g->frame.img);

	// détruire la fenêtre
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);

	// free la map
	if (g->world.map)
		free_map(g->world.map, g->world.map_h);

	// sur Linux, si tu utilises mlx_destroy_display:
	// if (g->mlx) { mlx_destroy_display(g->mlx); free(g->mlx); }
}