#include "cub3d.h"

static int	init_world(t_game *g, const char *map_path)
{
    if (!map_path || *map_path == '\0')
        return (print_error("Missing map path"));
    if (parse_cub((char *)map_path, g) != 0)
        return (1);
    if (init_player_from_spawn(g) != 0)
        return (1);
    return (0);
}

static int	init_graphics(t_game *g)
{
    if (init_mlx(g) != 0)
        return (1);
    if (init_images(g) != 0)
        return (1);
    if (init_textures_from_paths(g) != 0)
        return (1);
    return (0);
}

int	game_init(t_game *g, const char *map_path)
{
    g->world.floor_color = -1;
    g->world.ceiling_color = -1;
    g->world.paths.no = NULL;
    g->mlx = NULL;
    g->win = NULL;
    if (init_world(g, map_path) != 0)
    {
        game_destroy(g);
        return (1);
    }
    if (init_graphics(g) != 0)
    {
        game_destroy(g);
        return (1);
    }
    debug_dump_state(&g->world, &g->player, map_path);
    return (0);
}
