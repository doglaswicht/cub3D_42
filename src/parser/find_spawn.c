/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_spawn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:05:40 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/04 11:39:39 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	is_spawn_tile(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static	void	set_dir(t_player *spawn, double dx, double dy)
{
	spawn->dir.x = dx;
	spawn->dir.y = dy;
	spawn->plane.x = -dy * 0.66;
	spawn->plane.y = dx * 0.66;
}

static	void	assign_spawn(t_world *w, int x, int y, char tile)
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

static	int	find_spawn_in_line(t_world *w, int y, int *found)
{
	int	x;

	x = 0;
	while (w->map[y][x])
	{
		if (is_spawn_tile(w->map[y][x]))
		{
			if (*found)
				return (print_error("Multiple player spawns found"));
			assign_spawn(w, x, y, w->map[y][x]);
			*found = 1;
		}
		x++;
	}
	return (0);
}

int	find_player_spawn(t_world *w)
{
	int	y;
	int	found;

	if (!w || !w->map)
		return (print_error("World map not initialized"));
	found = 0;
	y = 0;
	while (w->map[y])
	{
		if (find_spawn_in_line(w, y, &found) == -1)
			return (-1);
		y++;
	}
	if (!found)
		return (print_error("Player spawn not found"));
	return (0);
}
