/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_column_rendering.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:39:26 by csturny           #+#    #+#             */
/*   Updated: 2025/11/16 13:39:27 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Fills basic rendering info for a column from raycast results.
 * @param col Pointer to the column to fill.
 * @param rc Pointer to the raycasting results.
 *
 * Copies distance, height, draw positions, and wall side info to the column.
 */
void	fill_column_basic(t_column *col, const t_raycast *rc)
{
	col->perp_dist = rc->perp_wall_dist;
	col->line_height = rc->line_height;
	col->draw_start = rc->draw_start;
	col->draw_end = rc->draw_end;
	col->side = rc->side;
}

/**
 * @brief Fills texture mapping info for a column from raycast results.
 * @param g Pointer to the game state.
 * @param col Pointer to the column to fill.
 * @param rc Pointer to the raycasting results.
 *
 * Determines wall face, hit position, and texture X coordinate for the column.
 */
void	fill_column_tex(const t_game *g, t_column *col, const t_raycast *rc)
{
	col->face = get_face(rc);
	col->wall_x = compute_wall_x(g, rc);
	col->tex_x = compute_tex_x(g, rc, col->wall_x, col->face);
}
