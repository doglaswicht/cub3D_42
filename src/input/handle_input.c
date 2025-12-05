/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:39:32 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/05 14:20:03 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Handles key press events and updates the game key state.
 * @param key Key code pressed.
 * @param g Pointer to the game state.
 * @return Always returns 0.
 *
 * Sets the corresponding key flag in the game state to 1.
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

/**
 * @brief Handles key release events and updates the game key state.
 * @param key Key code released.
 * @param g Pointer to the game state.
 * @return Always returns 0.
 *
 * Sets the corresponding key flag in the game state to 0.
 */
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

/**
 * @brief Handles rotation input and applies rotation to the player.
 * @param g Pointer to the game state.
 * @return 1 if rotation occurred, 0 otherwise.
 *
 * Rotates the player left or right if the corresponding key is pressed.
 */
static int	handle_rotate(t_game *g)
{
	int	changed;

	changed = 0;
	if (g->keys.left)
	{
		rotate_player(g, -ROT_SPEED);
		changed = 1;
	}
	if (g->keys.right)
	{
		rotate_player(g, ROT_SPEED);
		changed = 1;
	}
	return (changed);
}

/**
 * @brief Handles all input and applies movement/rotation.
 * @param g Pointer to the game state.
 * @return 1 if any action occurred, 0 otherwise.
 *
 * Closes the window if ESC is pressed, applies movement and rotation.
 */
int	handle_input(t_game *g)
{
	int	changed;

	changed = 0;
	if (g->keys.esc)
		close_window(g);
	if (handle_move(g))
		changed = 1;
	if (handle_rotate(g))
		changed = 1;
	return (changed);
}
