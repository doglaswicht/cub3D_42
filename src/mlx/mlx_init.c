#include "cub3d.h"

static void set_null_mlx(t_game *g)
{
    g->mlx = NULL;
    g->win = NULL;
}

int init_mlx(t_game *g)
{
    set_null_mlx(g);
    g->mlx = mlx_init();
    if (!g->mlx)
        return (1);
    g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "cub3D");
    if (!g->win)
        return (1);
    return (0);
}