#include "cub3d.h"

static void safe_destroy_image(void *mlx, void *img)
{
    if (mlx && img)
        mlx_destroy_image(mlx, img);
}


static void destroy_textures(t_game *g)
{
    t_textures *t = &g->world.tx;

    safe_destroy_image(g->mlx, t->no.img);
    safe_destroy_image(g->mlx, t->so.img);
    safe_destroy_image(g->mlx, t->ea.img);
    safe_destroy_image(g->mlx, t->we.img);

    t->no.img = NULL;
    t->so.img = NULL;
    t->ea.img = NULL;
    t->we.img = NULL;
}

/*
void game_destroy(t_game *g)
{
    if (g->frame.img)
        mlx_destroy_image(g->mlx, g->frame.img);
    destroy_textures(g);
    if (g->win)
        mlx_destroy_window(g->mlx, g->win);
#ifdef __linux__
    if (g->mlx)
        mlx_destroy_display(g->mlx);
#endif
    if (g->mlx)
        free(g->mlx);
    if (g->world.map)
        free_map(g->world.map, g->world.map_h); // si allouée dynamiquement
}
*/

void game_destroy(t_game *g)
{
    if (!g)
        return;

    safe_destroy_image(g->mlx, g->frame.img);
    destroy_textures(g);

    if (g->win && g->mlx)
        mlx_destroy_window(g->mlx, g->win);

    if (g->mlx)
    {
        mlx_destroy_display(g->mlx);
        free(g->mlx);
    }

    destroy_world(&g->world);
}


int close_window(t_game *g)
{
    game_destroy(g);
    exit(0);
    return (0);
}
