/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_from_spawn.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:57:37 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/05 14:17:04 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Checks if the player spawn is properly initialized in the world.
 * @param world Pointer to the world structure.
 * @return 1 if spawn is ready, 0 otherwise.
 *
 * Returns true if the spawn direction is non-zero.
 */
static int	spawn_ready(const t_world *world)
{
	if (!world)
		return (0);
	return (world->spawn.dir.x != 0.0 || world->spawn.dir.y != 0.0);
}

/**
 * @brief Initializes the player from the spawn data in the world.
 * @param game Pointer to the game state.
 * @return 0 on success, error code otherwise.
 *
 * Checks that the game and spawn are valid, then copies spawn 
 * data to the player.
 */
int	init_player_from_spawn(t_game *game)
{
	if (!game)
		return (print_error("Invalid game instance"));
	if (!spawn_ready(&game->world))
		return (print_error("Player spawn not initialized"));
	game->player = game->world.spawn;
	return (0);
}
