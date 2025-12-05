/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:21:39 by csturny           #+#    #+#             */
/*   Updated: 2025/12/05 15:13:09 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Moves the player forward if the 'W' key is pressed.
 * @param g Pointer to the game state.
 * @return 1 if movement occurred, 0 otherwise.
 */
static int	move_forward(t_game *g)
{
	if (g->keys.w)
	{
		move_player(g, g->player.dir.x * MOVE_SPEED,
			g->player.dir.y * MOVE_SPEED);
		return (1);
	}
	return (0);
}

/**
 * @brief Moves the player backward if the 'S' key is pressed.
 * @param g Pointer to the game state.
 * @return 1 if movement occurred, 0 otherwise.
 */
static int	move_backward(t_game *g)
{
	if (g->keys.s)
	{
		move_player(g, -g->player.dir.x * MOVE_SPEED,
			-g->player.dir.y * MOVE_SPEED);
		return (1);
	}
	return (0);
}

/**
 * @brief Moves the player left (strafe) if the 'A' key is pressed.
 * @param g Pointer to the game state.
 * @return 1 if movement occurred, 0 otherwise.
 */
static int	move_left(t_game *g)
{
	if (g->keys.a)
	{
		move_player(g, -g->player.plane.x * MOVE_SPEED,
			-g->player.plane.y * MOVE_SPEED);
		return (1);
	}
	return (0);
}

/**
 * @brief Moves the player right (strafe) if the 'D' key is pressed.
 * @param g Pointer to the game state.
 * @return 1 if movement occurred, 0 otherwise.
 */
static int	move_right(t_game *g)
{
	if (g->keys.d)
	{
		move_player(g, g->player.plane.x * MOVE_SPEED,
			g->player.plane.y * MOVE_SPEED);
		return (1);
	}
	return (0);
}

/**
 * @brief Handles all movement input for the player.
 * @param g Pointer to the game state.
 * @return 1 if any movement occurred, 0 otherwise.
 *
 * Calls the movement functions for each direction and returns 1
 * if any movement was made.
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
