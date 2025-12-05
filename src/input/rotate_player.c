/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:39:57 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/05 14:22:48 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Rotates the player's direction and camera plane by a given angle.
 * @param g Pointer to the game state.
 * @param angle Rotation angle in radians (positive: right, negative: left).
 *
 * Applies a 2D rotation to the direction and plane vectors 
 * using the given angle.
 * This changes the player's facing direction and field of view orientation.
 */
void	rotate_player(t_game *g, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->player.dir.x;
	old_plane_x = g->player.plane.x;
	g->player.dir.x = g->player.dir.x * cos(angle)
		- g->player.dir.y * sin(angle);
	g->player.dir.y = old_dir_x * sin(angle)
		+ g->player.dir.y * cos(angle);
	g->player.plane.x = g->player.plane.x * cos(angle)
		- g->player.plane.y * sin(angle);
	g->player.plane.y = old_plane_x * sin(angle)
		+ g->player.plane.y * cos(angle);
}
