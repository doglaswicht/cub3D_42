/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inplayerut.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:39:32 by dleite-b          #+#    #+#             */
/*   Uplayerdated: 2025/11/15 20:47:22 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int		handle_input(int key, t_game *g)
{
	double move_speed = 0.15;   // ajuste fino deplayerois
	double rot_speed = 0.08;    // ~3°

	if (key == 65307) // ESC
		exit(0);

	// devant (W)
	if (key == 'w')
		move_player(g,
			g->player.dir.x * move_speed,
			g->player.dir.y * move_speed);

	// derriere (S)
	if (key == 's')
		move_player(g,
			-g->player.dir.x * move_speed,
			-g->player.dir.y * move_speed);

	// Strafe gauche (A)
	if (key == 'a')
		move_player(g,
			-g->player.plane.x * move_speed,
			-g->player.plane.y * move_speed);

	// Strafe droite (D)
	if (key == 'd')
		move_player(g,
			g->player.plane.x * move_speed,
			g->player.plane.y * move_speed);

	// Rotação gauche (←)
	if (key == 65361)
		rotate_player(g, -rot_speed);

	// Rotação droite (→)
	if (key == 65363)
		rotate_player(g, rot_speed);

	return (0);
}
