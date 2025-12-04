/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:21:34 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/04 11:08:46 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	game_run(t_game *g)
{
	mlx_hook(g->win, EV_DESTROY, 0, close_window, g);
	mlx_hook(g->win, EV_KEYPRESS, 1L << 0, key_press, g);
	mlx_hook(g->win, EV_KEYPRELEASE, 1L << 1, key_release, g);
	mlx_loop_hook(g->mlx, game_loop, g);
	mlx_loop(g->mlx);
}
