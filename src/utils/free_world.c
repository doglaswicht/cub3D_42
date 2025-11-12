/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:44:15 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/12 17:10:47 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_paths(t_tex_paths *paths)
{
	if (!paths)
		return ;
	free(paths->no);
	free(paths->so);
	free(paths->we);
	free(paths->ea);
	paths->no = NULL;
	paths->so = NULL;
	paths->we = NULL;
	paths->ea = NULL;
}

void	destroy_world(t_world *w)
{
	if (!w)
		return ;
	if (w->map)
		free_map(w->map, w->map_h);
	w->map = NULL;
	w->map_w = 0;
	w->map_h = 0;
	free_paths(&w->paths);
	w->floor_color = -1;
	w->ceiling_color = -1;
	ft_bzero(&w->spawn, sizeof(t_player));
}
