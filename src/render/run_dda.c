/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:40:11 by csturny           #+#    #+#             */
/*   Updated: 2025/11/16 13:40:12 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Runs the DDA algorithm to find the next wall hit by the ray.
 * @param g Pointer to the game state.
 * @param rc Pointer to the raycasting structure (input/output).
 *
 * Steps through the map grid along the ray direction until a wall is hit
 * or the ray goes out of bounds. Updates the raycasting structure with
 * the hit position and side (vertical/horizontal).
 */
void	run_dda(const t_game *g, t_raycast *rc)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (rc->side_dist.x < rc->side_dist.y)
		{
			rc->side_dist.x += rc->delta_dist.x;
			rc->map.x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist.y += rc->delta_dist.y;
			rc->map.y += rc->step_y;
			rc->side = 1;
		}
		if (rc->map.x < 0 || rc->map.x >= g->world.map_w
			|| rc->map.y < 0 || rc->map.y >= g->world.map_h)
			break ;
		if (g->world.map[(int)rc->map.y][(int)rc->map.x] == '1')
			hit = 1;
	}
}
