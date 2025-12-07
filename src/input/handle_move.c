/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:21:39 by csturny           #+#    #+#             */
/*   Updated: 2025/12/07 14:58:10 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Moves the player forward if the 'W' key is pressed.
 *
 * Multiplies the movement speed by delta_time for frame-rate independence.
 * @param g Pointer to the game state.
 * @return 1 if movement occurred, 0 otherwise.
 */
static int	move_forward(t_game *g)
{
	if (g->keys.w)
	{
		move_player(g,
			g->player.dir.x * MOVE_SPEED * g->delta_time,
			g->player.dir.y * MOVE_SPEED * g->delta_time);
		return (1);
	}
	return (0);
}

/**
 * @brief Moves the player backward if the 'S' key is pressed.
 *
 * Multiplies the movement speed by delta_time for frame-rate independence.
 * @param g Pointer to the game state.
 * @return 1 if movement occurred, 0 otherwise.
 */
static int	move_backward(t_game *g)
{
	if (g->keys.s)
	{
		move_player(g,
			-g->player.dir.x * MOVE_SPEED * g->delta_time,
			-g->player.dir.y * MOVE_SPEED * g->delta_time);
		return (1);
	}
	return (0);
}

/**
 * @brief Moves the player left (strafe) if the 'A' key is pressed.
 *
 * Multiplies the movement speed by delta_time for frame-rate independence.
 * @param g Pointer to the game state.
 * @return 1 if movement occurred, 0 otherwise.
 */
static int	move_left(t_game *g)
{
	if (g->keys.a)
	{
		move_player(g,
			-g->player.plane.x * MOVE_SPEED * g->delta_time,
			-g->player.plane.y * MOVE_SPEED * g->delta_time);
		return (1);
	}
	return (0);
}

/**
 * @brief Moves the player right (strafe) if the 'D' key is pressed.
 *
 * Multiplies the movement speed by delta_time for frame-rate independence.
 * @param g Pointer to the game state.
 * @return 1 if movement occurred, 0 otherwise.
 */
static int	move_right(t_game *g)
{
	if (g->keys.d)
	{
		move_player(g,
			g->player.plane.x * MOVE_SPEED * g->delta_time,
			g->player.plane.y * MOVE_SPEED * g->delta_time);
		return (1);
	}
	return (0);
}

/**
 * @brief Handles all movement input for the player.
 *
 * Calls the movement functions for each direction and returns 1
 * if any movement was made.
 * @param g Pointer to the game state.
 * @return 1 if any movement occurred, 0 otherwise.
 */
int	handle_move(t_game *g)
{
	int	changed;

	changed = 0;
	if (move_forward(g))
		changed = 1;
	if (move_backward(g))
		changed = 1;
	if (move_left(g))
		changed = 1;
	if (move_right(g))
		changed = 1;
	return (changed);
}
