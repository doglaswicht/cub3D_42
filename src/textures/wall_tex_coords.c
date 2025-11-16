/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_tex_coords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:59:34 by csturny           #+#    #+#             */
/*   Updated: 2025/11/16 14:01:11 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Computes the exact wall hit position for texture mapping.
 * @param g Pointer to the game state.
 * @param rc Pointer to the raycasting result structure.
 * @return Fractional position (0.0 to <1.0) along the wall.
 *
 * Calculates where the ray hit the wall, used to select
 *  the correct texel column.
 */
double	compute_wall_x(const t_game *g, const t_raycast *rc)
{
	double	wall_x;
	double	fraction;

	if (rc->side == 0)
		wall_x = g->player.pos.y + rc->perp_wall_dist * rc->raydir.y;
	else
		wall_x = g->player.pos.x + rc->perp_wall_dist * rc->raydir.x;
	fraction = wall_x - floor(wall_x);
	return (fraction);
}

/**
 * @brief Computes the X coordinate in the wall texture for the current column.
 * @param g Pointer to the game state.
 * @param rc Pointer to the raycasting result structure.
 * @param wall_x Fractional wall hit position (from compute_wall_x).
 * @param face Wall face identifier 
 * (FACE_NORTH, FACE_SOUTH, FACE_EAST, FACE_WEST).
 * @return Texture X coordinate (column index).
 *
 * Converts the wall hit position to a texture column, 
 * flipping if needed for orientation.
 */
int	compute_tex_x(const t_game *g, const t_raycast *rc, double wall_x, int face)
{
	const t_image	*tex;
	int				tx;

	tex = get_tex_for_face(&g->world.tx, face);
	tx = (int)(wall_x * (double)tex->w);
	if (rc->side == 0 && rc->raydir.x > 0)
		tx = tex->w - tx - 1;
	if (rc->side == 1 && rc->raydir.y < 0)
		tx = tex->w - tx - 1;
	return (tx);
}
