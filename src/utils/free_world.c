/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:44:15 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/05 15:09:55 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Frees all texture path strings in a t_tex_paths structure.
 *
 * Releases memory for each texture path and sets the pointers to NULL.
 * @param paths Pointer to the t_tex_paths structure to free.
 */
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

/**
 * @brief Frees all resources associated with a t_world structure.
 *
 * Frees the map, texture paths, and resets all fields to default values.
 * @param w Pointer to the t_world structure to destroy.
 */
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
