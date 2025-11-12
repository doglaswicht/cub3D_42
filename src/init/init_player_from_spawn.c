/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_from_spawn                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:57:37 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/12 15:57:38 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	spawn_ready(const t_world *world)
{
	if (!world)
		return (0);
	return (world->spawn.dir.x != 0.0 || world->spawn.dir.y != 0.0);
}

int	init_player_from_spawn(t_game *game)
{
	if (!game)
		return (print_error("Invalid game instance"));
	if (!spawn_ready(&game->world))
		return (print_error("Player spawn not initialized"));
	game->player = game->world.spawn;
	return (0);
}
