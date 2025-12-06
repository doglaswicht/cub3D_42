/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:21:34 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/06 13:10:40 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Main game loop called by MLX at each frame.
 * @param param Pointer to the game state (t_game).
 * @return Always returns 0.
 *
 * Handles user input, triggers redraw if needed, renders the frame,
 * and sleeps briefly if no redraw is required.
 */
int	game_loop(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (handle_input(g))
		g->need_redraw = 1;
	if (g->need_redraw)
	{
		render_frame(g);
		g->need_redraw = 0;
	}
	else
		usleep(10000);
	return (0);
}

/**
 * @brief Sets up MLX event hooks and starts the main loop.
 * @param g Pointer to the game state.
 *
 * Registers window close, key press/release, and frame loop hooks,
 * then enters the MLX main loop.
 */
void	game_run(t_game *g)
{
	mlx_hook(g->win, EV_DESTROY, 0, close_window, g);
	mlx_hook(g->win, EV_KEYPRESS, 1L << 0, key_press, g);
	mlx_hook(g->win, EV_KEYPRELEASE, 1L << 1, key_release, g);
	mlx_loop_hook(g->mlx, game_loop, g);
	mlx_loop(g->mlx);
}
