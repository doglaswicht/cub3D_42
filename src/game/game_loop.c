#include "cub3d.h"
/*
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
}*/

void handle_input(t_game *g)
{
    (void)g;
    // Rien ici pour l’instant — ce sera fait par le module mouvement
}

static int key_hook(int key, t_game *g)
{
    printf("key=%d\n", key); // ← Ajoute cette ligne pour debug
    fflush(stdout);
    if (key == KEY_ESC)
        return (close_window(g));
    return (0);
}

int game_loop(void *param)
{
    t_game *g;

    g = (t_game *)param;
    handle_input(g);        // stub tant que A n’a pas branché les inputs
    render_frame(g);
    return (0);
}

void game_run(t_game *g)
{
    mlx_hook(g->win, EV_DESTROY, 0, close_window, g);
    mlx_hook(g->win, EV_KEYPRESS, 0, key_hook, g);
    mlx_loop_hook(g->mlx, game_loop, g);
    mlx_loop(g->mlx);
}
