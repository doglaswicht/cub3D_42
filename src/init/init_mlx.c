/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:41:30 by dleite-b          #+#    #+#             */
/*   Updated: 2025/10/21 16:58:44 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_game(t_game *game, char *map_path)
{
    game->mlx = mlx_init();
    if(!game->mlx)
    {
        printf("Error\n Failed to initializate MLX\n");
        return (-1);
    }
    game->win = mlx_new_window(game->mlx, 800, 600, "cube3D");
    if(!game->win)
    {
        printf("Error\nFailed to create window\n");
        return (-1);
    }
    if(parse_cub(map_path, game) == -1)
        return(-1);
    return 0;
}