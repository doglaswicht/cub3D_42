/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:39:45 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/10 15:36:24 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Moves the player by the given delta, with wall collision detection.
 *
 * Attempts to move the player by (dx, dy). If the new position would collide
 * with a wall, the movement along that axis is blocked.
 *
 * @param g Pointer to the game state.
 * @param dx Delta to add to the player's X position.
 * @param dy Delta to add to the player's Y position.
 */
void	move_player(t_game *g, double dx, double dy)
{
	double	new_x;
	double	new_y;

	new_x = g->player.pos.x + dx;
	new_y = g->player.pos.y + dy;
	if (!is_wall_with_radius(&g->world, new_x, g->player.pos.y))
		g->player.pos.x = new_x;
	if (!is_wall_with_radius(&g->world, g->player.pos.x, new_y))
		g->player.pos.y = new_y;
}
