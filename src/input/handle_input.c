/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:39:32 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/20 12:27:00 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
t		handle_input(int key, t_game *g)
{
	double move_speed;
	double rot_speed;

	move_speed = 0.15;
	rot_speed = 0.08;
	if (key == 65307)
		return (close_window(g));
	if (key == 'w')
		move_player(g, g->player.dir.x * move_speed,
			g->player.dir.y * move_speed);
	if (key == 's')
		move_player(g, -g->player.dir.x * move_speed,
			-g->player.dir.y * move_speed);
	if (key == 'a')
		move_player(g, -g->player.plane.x * move_speed,
			-g->player.plane.y * move_speed);
	if (key == 'd')
		move_player(g, g->player.plane.x * move_speed,
			g->player.plane.y * move_speed);
	if (key == 65361)
		rotate_player(g, -rot_speed);
	if (key == 65363)
		rotate_player(g, rot_speed);
	return (0);
}
*/

int	key_press(int key, t_game *g)
{
	if (key == KEY_ESC)
		g->keys.esc = 1;
	if (key == KEY_W)
		g->keys.w = 1;
	if (key == KEY_S)
		g->keys.s = 1;
	if (key == KEY_A)
		g->keys.a = 1;
	if (key == KEY_D)
		g->keys.d = 1;
	if (key == KEY_LEFT)
		g->keys.left = 1;
	if (key == KEY_RIGHT)
		g->keys.right = 1;
	return (0);
}

int	key_release(int key, t_game *g)
{
	if (key == KEY_ESC)
		g->keys.esc = 0;
	if (key == KEY_W)
		g->keys.w = 0;
	if (key == KEY_S)
		g->keys.s = 0;
	if (key == KEY_A)
		g->keys.a = 0;
	if (key == KEY_D)
		g->keys.d = 0;
	if (key == KEY_LEFT)
		g->keys.left = 0;
	if (key == KEY_RIGHT)
		g->keys.right = 0;
	return (0);
}

void	handle_input(t_game *g)
{
	double	move;
	double	rot;

	move = 0.03;
	rot = 0.01;
	if (g->keys.esc)
		close_window(g);
	if (g->keys.w)
		move_player(g, g->player.dir.x * move, g->player.dir.y * move);
	if (g->keys.s)
		move_player(g, -g->player.dir.x * move, -g->player.dir.y * move);
	if (g->keys.a)
		move_player(g, -g->player.plane.x * move, -g->player.plane.y * move);
	if (g->keys.d)
		move_player(g, g->player.plane.x * move, g->player.plane.y * move);
	if (g->keys.left)
		rotate_player(g, -rot);
	if (g->keys.right)
		rotate_player(g, rot);
}
