#include "cub3d.h"

void	game_run(t_game *g)
{
	// première frame (plus tard tu utiliseras un loop_hook)
	render_frame(g);

	// hook fermeture fenêtre
	mlx_hook(g->win, 17, 0, close_window, g);

	// plus tard tu ajouteras aussi:
	// mlx_hook(g->win, 2, 1L<<0, key_press, g);
	// mlx_hook(g->win, 3, 1L<<1, key_release, g);
	// mlx_loop_hook(g->mlx, game_loop, g);

	mlx_loop(g->mlx);
}