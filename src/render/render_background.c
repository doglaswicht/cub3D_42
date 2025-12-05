/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:38:44 by csturny           #+#    #+#             */
/*   Updated: 2025/12/05 15:12:31 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Fills a row of pixels with a given color.
 *
 * Writes the specified color to each pixel in the row.
 * @param row Pointer to the start of the row in the image buffer.
 * @param w Number of pixels to fill.
 * @param color The color value to write.
 */
static void	fill_row(int *row, int w, int color)
{
	int	x;

	x = 0;
	while (x < w)
	{
		row[x] = color;
		x++;
	}
}

/**
 * @brief Renders the background (ceiling and floor) of the frame.
 *
 * Fills the top half of the screen with the ceiling color and the
 * bottom half with the floor color.
 * Uses direct buffer access for performance.
 * @param g Pointer to the game structure (contains the frame buffer
 * and world colors).
 */
void	render_background(t_game *g)
{
	t_bg_vars	v;

	v.pixels = (int *)g->frame.addr;
	v.line_len = g->frame.line_len / 4;
	v.half_h = g->frame.h / 2;
	v.y = 0;
	while (v.y < v.half_h)
	{
		fill_row(v.pixels + v.y * v.line_len, g->frame.w,
			g->world.ceiling_color);
		v.y++;
	}
	v.y = v.half_h;
	while (v.y < g->frame.h)
	{
		fill_row(v.pixels + v.y * v.line_len, g->frame.w, g->world.floor_color);
		v.y++;
	}
}
