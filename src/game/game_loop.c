/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:21:34 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/03 15:32:25 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(void *param)
{
	t_game	*g;

	g = (t_game *)param;

	// mise a jourddes inputs
	if (handle_input(g))
		g->need_redraw = 1;
	if (g->need_redraw)
	{
		render_frame(g);
		g->need_redraw = 0;
	}
	else
    {
        usleep(10000); // 10 ms = 0.01s, réduit la charge CPU en idle
    }
	return (0);
}

void	game_run(t_game *g)
{
	mlx_hook(g->win, EV_DESTROY, 0, close_window, g);
	mlx_hook(g->win, EV_KEYPRESS, 1L << 0, key_press, g);
	mlx_hook(g->win, EV_KEYPRELEASE, 1L << 1, key_release, g);
	mlx_loop_hook(g->mlx, game_loop, g);
	mlx_loop(g->mlx);
}
