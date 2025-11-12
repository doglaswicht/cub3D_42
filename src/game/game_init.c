#include "cub3d.h"

// Provisoir

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

// version hardcode_world: pour avoir valeur a tester
// A remplacer par Doglas
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
	if (init_mlx(g) != 0)  // a voir avec Doglas qui reprend!!!
		return (1);

	// 4) Initialisation image frame
	if (init_images(g) != 0) // a voir avec Doglas qui reprend
		return (1);
	
	// 5) Initialisation textures
	if (init_textures_hardcode(g) != 0) // provisoir
	{
		return (1);
	}

	return (0);
}

