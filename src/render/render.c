#include "cub3d.h"

// toute la frame.
/**
 * @brief Renders the entire frame: background, walls, and displays it.
 * @param g Pointer to the game state.
 */
void	render_frame(t_game *g)
{
	t_column	cols[WIN_W];

	render_background(g);
	cast_rays(g, cols);
	debug_faces_once(cols);
	render_walls(g, cols);
	mlx_put_image_to_window(g->mlx, g->win, g->frame.img, 0, 0);
}
