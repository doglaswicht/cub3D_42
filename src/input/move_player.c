/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:39:45 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/05 14:22:15 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Moves the player by (dx, dy) if there is no wall collision.
 * @param g Pointer to the game state.
 * @param dx Delta movement in X direction.
 * @param dy Delta movement in Y direction.
 *
 * Checks for wall collisions separately on X and Y axes,
 * and updates the player's position if the move is valid.
 */
void	move_player(t_game *g, double dx, double dy)
{
	double	new_x;
	double	new_y;

	new_x = g->player.pos.x + dx;
	new_y = g->player.pos.y + dy;
	if (!is_wall(&g->world, new_x, g->player.pos.y))
		g->player.pos.x = new_x;
	if (!is_wall(&g->world, g->player.pos.x, new_y))
		g->player.pos.y = new_y;
}
