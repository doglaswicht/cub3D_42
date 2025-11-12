#include "cub3d.h"

// toute la frame.
/**
 * @brief Renders the entire frame: background, walls, and displays it.
 * @param g Pointer to the game state.
 */
void render_frame(t_game *g)
{
	t_column cols[WIN_W];

	render_background(g);          // ciel + sol
	cast_rays(g, cols); // calcule toutes les colonnes (raycasting)
	render_walls(g, cols); // dessine toutes les colonnes
	mlx_put_image_to_window(g->mlx, g->win, g->frame.img, 0, 0);
}

