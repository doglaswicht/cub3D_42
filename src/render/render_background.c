/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:38:44 by csturny           #+#    #+#             */
/*   Updated: 2025/12/05 18:17:05 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Fills a row of pixels with a given color.
 *
 * Writes the specified color to each pixel in the row.
 * @param row_start Pointer to the start of the row in the image buffer.
 * @param row_width Number of pixels (width) to fill in the row.
 * @param fill_color The color value to write.
 */
static void	fill_row(int *row_start, int row_width, int fill_color)
{
	int	col_index;

	col_index = 0;
	while (col_index < row_width)
	{
		row_start[col_index] = fill_color;
		col_index++;
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

	v.pixels_buffer = (int *)g->frame.addr;
	v.pixels_per_row = g->frame.line_len / 4;
	v.half_height = g->frame.h / 2;
	v.row_index = 0;
	while (v.row_index < v.half_height)
	{
		fill_row(v.pixels_buffer + v.row_index * v.pixels_per_row, g->frame.w,
			g->world.ceiling_color);
		v.row_index++;
	}
	v.row_index = v.half_height;
	while (v.row_index < g->frame.h)
	{
		fill_row(v.pixels_buffer + v.row_index * v.pixels_per_row,
			g->frame.w, g->world.floor_color);
		v.row_index++;
	}
}
