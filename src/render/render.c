/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:37:45 by csturny           #+#    #+#             */
/*   Updated: 2025/12/02 13:20:55 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
