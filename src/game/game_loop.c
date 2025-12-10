/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:21:34 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/10 14:45:58 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Calculates the time elapsed since the last call (delta time).
 *
 * Uses gettimeofday to measure the time between frames, returning the
 * elapsed time in seconds. On the first call, returns a default value
 * based on the TARGET_FPS macro (e.g., 1.0 / TARGET_FPS).
 *
 * @return Time elapsed since the last call, in seconds.
 */
double	get_delta_time(void)
{
	static struct timeval	last;
	struct timeval			now;
	double					delta;

	gettimeofday(&now, NULL);
	if (last.tv_sec != 0)
		delta = (now.tv_sec - last.tv_sec)
			+ (now.tv_usec - last.tv_usec) / 1000000.0;
	else
		delta = 1.0 / TARGET_FPS;
	last = now;
	return (delta);
}

/**
 * @brief Main game loop called by MLX at each frame.
 *
 * Updates the delta time, handles user input, triggers redraw if needed,
 * renders the frame, and enforces a maximum frame rate (TARGET_FPS).
 *
 * @param param Pointer to the game state (t_game).
 * @return Always returns 0.
 */
int	game_loop(void *param)
{
	t_game	*g;
	double	start;
	double	elapsed;

	g = (t_game *)param;
	start = get_time_in_seconds();
	g->delta_time = get_delta_time();
	if (handle_input(g))
		g->need_redraw = 1;
	if (g->need_redraw)
	{
		render_frame(g);
		g->need_redraw = 0;
		print_fps();
	}
	else
		usleep(10000);
	elapsed = get_time_in_seconds() - start;
	if (elapsed < (1.0 / TARGET_FPS))
		usleep(((1.0 / TARGET_FPS) - elapsed) * 1000000.0);
	return (0);
}

/**
 * @brief Sets up MLX event hooks and starts the main loop.
 * @param g Pointer to the game state.
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
