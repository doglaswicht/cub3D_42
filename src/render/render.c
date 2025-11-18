/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:37:45 by csturny           #+#    #+#             */
/*   Updated: 2025/11/18 15:34:14 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// toute la frame.
/**
 * @brief Renders the entire frame (background and walls) and displays it.
 * @param g Pointer to the game state.
 *
 * Draws the background, casts rays, renders all wall columns,
 * and pushes the completed frame buffer to the window.
 */
void	render_frame(t_game *g)
{
	t_column	cols[WIN_W];

	render_background(g);
	cast_rays(g, cols);
	render_walls(g, cols);
	mlx_put_image_to_window(g->mlx, g->win, g->frame.img, 0, 0);
}


/**
 * @brief Renders the entire frame, including debug info.
 * @param g Pointer to the game state.
 *
 * Draws the background, casts rays, fills columns, and renders all walls.
 * Displays debug info for selected columns on first call.
 * Finally, pushes the completed frame buffer to the window.
 */
/*
void	render_frame(t_game *g)
{
	t_column cols[WIN_W];
	t_raycast rc_debug[5];
	int idx[5] = {0, WIN_W/4, WIN_W/2, 3*WIN_W/4, WIN_W-1};

	render_background(g);
	cast_rays(g, cols, rc_debug, idx, 5);
	static int done = 0;
	if (!done) {
		done = 1;
		printf("\n==== DEBUG 5 COLONNES ====\n");
		debug_dump_column_table((const t_column[]){cols[idx[0]], cols[idx[1]], cols[idx[2]], cols[idx[3]], cols[idx[4]]}, idx);
		debug_dump_raycast_table(rc_debug, idx);
		printf("=========================\n\n");
		printf("CALL DEBUG FACES\n");
	}
	debug_faces_once(cols);
	render_walls(g, cols);
	mlx_put_image_to_window(g->mlx, g->win, g->frame.img, 0, 0);
}*/
