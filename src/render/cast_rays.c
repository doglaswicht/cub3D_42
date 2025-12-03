/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:39:03 by csturny           #+#    #+#             */
/*   Updated: 2025/12/02 19:21:18 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initializes the raycasting structure for a given screen column.
 * @param rc Pointer to the raycasting structure to initialize.
 * @param x Screen column index (0 to WIN_W-1).
 * @param g Pointer to the game state.
 */
static void	init_raycast(t_raycast *rc, int x, const t_game *g)
{
	double	camera_x;

	camera_x = 2.0 * x / (double)WIN_W - 1.0;
	ft_bzero(rc, sizeof(t_raycast));
	rc->raydir.x = g->player.dir.x + g->player.plane.x * camera_x;
	rc->raydir.y = g->player.dir.y + g->player.plane.y * camera_x;
	rc->map.x = (int)g->player.pos.x;
	rc->map.y = (int)g->player.pos.y;
}

/**
 * @brief Computes the perpendicular distance from the 
 * player to the wall hit by the ray.
 * @param g Pointer to the game state.
 * @param rc Pointer to the raycasting structure (input/output).
 *
 * Uses the side hit and ray direction to calculate the 
 * correct distance for projection.
 */
void	compute_perp_distance(const t_game *g, t_raycast *rc)
{
	if (rc->side == 0)
	{
		rc->perp_wall_dist = (rc->map.x - g->player.pos.x
				+ (1 - rc->step_x) / 2.0) / rc->raydir.x;
	}
	else
	{
		rc->perp_wall_dist = (rc->map.y - g->player.pos.y
				+ (1 - rc->step_y) / 2.0) / rc->raydir.y;
	}
	if (rc->perp_wall_dist <= 0.0)
		rc->perp_wall_dist = 0.0001;
}

/**
 * @brief Calculates the projected wall height and draw positions 
 * for the current ray.
 * @param rc Pointer to the raycasting structure (input/output).
 *
 * Sets the line height and the start/end positions 
 * for drawing the wall slice on screen.
 */
void	compute_wall_height(t_raycast *rc)
{
	rc->line_height = (int)(WIN_H / rc->perp_wall_dist);
	rc->draw_start = -rc->line_height / 2 + WIN_H / 2;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = rc->line_height / 2 + WIN_H / 2;
	if (rc->draw_end >= WIN_H)
		rc->draw_end = WIN_H - 1;
}

/**
 * @brief Casts all rays for the current frame and fills the columns array.
 * @param g Pointer to the game state.
 * @param cols Array of columns to fill (size WIN_W).
 */

void	cast_rays(const t_game *g, t_column cols[WIN_W])
{
	int			x;
	t_raycast	rc;

	x = 0;
	while (x < WIN_W)
	{
		init_raycast(&rc, x, g);
		compute_dda_params(g, &rc);
		run_dda(g, &rc);
		compute_perp_distance(g, &rc);
		compute_wall_height(&rc);
		fill_column_basic(&cols[x], &rc);
		fill_column_tex(g, &cols[x], &rc);
		x++;
	}
}
