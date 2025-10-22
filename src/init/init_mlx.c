/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:41:30 by dleite-b          #+#    #+#             */
/*   Updated: 2025/10/21 20:35:32 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_textures(t_textures *tx)
{
    tx->no = NULL;
    tx->so = NULL;
    tx->we = NULL;
    tx->ea = NULL;
    tx->w = 0;
    tx->h = 0;
}

static void init_world(t_world *world)
{
    world->spawn.x = 0.0;
    world->spawn.y = 0.0;
    world->spawn.dir_x = 0.0;
    world->spawn.dir_y = 0.0;
    world->spawn.plane_x = 0.0;
    world->spawn.plane_y = 0.0;
    init_textures(&world->tx);
    world->maps = NULL;
    world->floor_color = -1;
    world->ceiling_color = -1;
}

static void init_player(t_player *player)
{
    player->x = 0.0;
    player->y = 0.0;
    player->dir_x = 0.0;
    player->dir_y = 0.0;
    player->plane_x = 0.0;
    player->plane_y = 0.0;
}

int init_game(t_game *game, char *map_path)
{
    if (!game)
        return (-1);
    game->mlx = NULL;
    game->win = NULL;
    init_world(&game->world);
    init_player(&game->p);
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        printf("Error\n Failed to initializate MLX\n");
        return (-1);
    }
    game->win = mlx_new_window(game->mlx, 800, 600, "cube3D");
    if (!game->win)
    {
        printf("Error\nFailed to create window\n");
        return (-1);
    }
    if (parse_cub(map_path, game) == -1)
        return (-1);
    return (0);
}
