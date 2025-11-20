/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:39:57 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/20 11:30:27 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
	/* rotaciona vetor direcao*/
	/*rotaciona plano da camera FOV */
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
