/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:07:51 by csturny           #+#    #+#             */
/*   Updated: 2025/12/05 14:15:11 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initializes the game world from the map file.
 * @param g Pointer to the game state.
 * @param map_path Path to the .cub map file.
 * @return 0 on success, 1 on error.
 *
 * Parses the map, initializes the world and player spawn.
 */
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

/**
 * @brief Initializes the graphics context and images.
 * @param g Pointer to the game state.
 * @return 0 on success, 1 on error.
 *
 * Initializes MLX, frame image, and wall textures.
 */
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

/**
 * @brief Initializes the entire game state and resources.
 * @param g Pointer to the game state.
 * @param map_path Path to the .cub map file.
 * @return 0 on success, 1 on error.
 *
 * Sets default values, initializes world and graphics.
 * Destroys resources and returns error if any step fails.
 */
int	game_init(t_game *g, const char *map_path)
{
	g->world.floor_color = -1;
	g->world.ceiling_color = -1;
	g->world.paths.no = NULL;
	g->world.paths.so = NULL;
	g->world.paths.we = NULL;
	g->world.paths.ea = NULL;
	g->mlx = NULL;
	g->win = NULL;
	g->need_redraw = 1;
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
	return (0);
}
