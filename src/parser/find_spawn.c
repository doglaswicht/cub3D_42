/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_spawn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:05:40 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/12 14:30:54 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "cub3d.h"

static void set_dir(t_player *spawn, double dir_x, double dir_y)
{
	spawn->dir.x = dir_x;
	spawn->dir.y = dir_y;
	spawn->plane.x = -dir_y * 0.66;
	spawn->plane.y = dir_x * 0.66;
}

static void assign_spawn(t_world *w, int x, int y, char tile)
{
	w->spawn.pos.x = x + 0.5;
	w->spawn.pos.y = y + 0.5;
	if (tile == 'N')
		set_dir(&w->spawn, 0.0, -1.0);
	else if (tile == 'S')
		set_dir(&w->spawn, 0.0, 1.0);
	else if (tile == 'E')
		set_dir(&w->spawn, 1.0, 0.0);
	else if (tile == 'W')
		set_dir(&w->spawn, -1.0, 0.0);
	w->map[y][x] = '0';
}

int	find_player_spawn(t_world *w)
{
	int	x;
	int	y;
	int	found;

	if (!w || !w->map)
		return (print_error("World map not initialized"));
	found = 0;
	y = 0;
	while (w->map[y])
	{
		x = 0;
		while (w->map[y][x])
		{
			if (ft_strchr("NSEW", w->map[y][x]))
			{
				if (found)
					return (print_error("Multiple player spawns found"));
				assign_spawn(w, x, y, w->map[y][x]);
				found = 1;
			}
			x++;
		}
		y++;
	}
	if (!found)
		return (print_error("Player spawn not found"));
	return (0);
}
