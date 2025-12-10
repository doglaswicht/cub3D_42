/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:40:31 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/10 15:41:55 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Checks if a given (x, y) position is a wall or out of bounds.
 * @param w Pointer to the world structure.
 * @param x X coordinate (double, will be cast to int).
 * @param y Y coordinate (double, will be cast to int).
 * @return 1 if the position is a wall or out of the map, 0 otherwise.
 *
 * Returns 1 if the coordinates are outside the map, the line is missing,
 * the position is beyond the line length, or the cell is a wall ('1').
 */
int	is_wall(const t_world *w, double x, double y)
{
	int	mx;
	int	my;
	int	line_len;

	mx = (int)x;
	my = (int)y;
	if (mx < 0 || my < 0 || my >= w->map_h)
		return (1);
	if (!w->map[my])
		return (1);
	line_len = ft_strlen(w->map[my]);
	if (mx >= line_len)
		return (1);
	if (w->map[my][mx] == '1')
		return (1);
	return (0);
}

int	is_wall_with_radius(const t_world *w, double x, double y)
{
	if (is_wall(w, x - PLAYER_RADIUS, y - PLAYER_RADIUS))
		return (1);
	if (is_wall(w, x + PLAYER_RADIUS, y - PLAYER_RADIUS))
		return (1);
	if (is_wall(w, x - PLAYER_RADIUS, y + PLAYER_RADIUS))
		return (1);
	if (is_wall(w, x + PLAYER_RADIUS, y + PLAYER_RADIUS))
		return (1);
	return (0);
}
