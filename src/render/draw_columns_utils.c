/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_columns_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:39:14 by csturny           #+#    #+#             */
/*   Updated: 2025/12/05 13:08:29 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Clamps the wall draw start position to the top of the screen.
 * @param col Pointer to the column data.
 * @return The clamped draw start position (minimum 0).
 */
int	clamp_draw_start(const t_column *col)
{
	if (col->draw_start < 0)
		return (0);
	return (col->draw_start);
}

/**
 * @brief Clamps the wall draw end position to the bottom of the screen.
 * @param col Pointer to the column data.
 * @return The clamped draw end position (maximum WIN_H - 1).
 */
int	clamp_draw_end(const t_column *col)
{
	if (col->draw_end >= WIN_H)
		return (WIN_H - 1);
	return (col->draw_end);
}

/**
 * @brief Clamps the texture X coordinate to valid range.
 * @param col Pointer to the column data.
 * @param tex Pointer to the texture image.
 * @return The clamped texture X coordinate (between 0 and tex->w - 1).
 */
int	clamp_tex_x(const t_column *col, const t_image *tex)
{
	if (col->tex_x < 0)
		return (0);
	if (col->tex_x >= tex->w)
		return (tex->w - 1);
	return (col->tex_x);
}

/**
 * @brief Returns the shaded color for a wall pixel.
 * @param col Pointer to the column data (contains wall info).
 * @param tex Pointer to the texture image.
 * @param tex_x X coordinate in the texture.
 * @param y Y coordinate on the screen (current pixel).
 * @return The (possibly shaded) color value for the pixel.
 *
 * Computes the Y coordinate in the texture, reads the texel color,
 * and applies shading if the wall side is 1 (vertical wall).
 */
/*
int	get_shaded_color(const t_column *col, const t_image *tex, int tex_x, int y)
{
	int	color;
	int	tex_y;

	tex_y = get_tex_y_from_start(tex, col->line_height, y,
			clamp_draw_start(col));
	color = get_texel(tex, tex_x, tex_y);
	if (col->side == 1)
		color = (color >> 1) & 0x7F7F7F;
	return (color);
}*/

#ifdef ENABLE_SHADING

int	get_shaded_color(const t_column *col, const t_image *tex, int tex_x, int y)
{
	int	color;
	int	tex_y;

	tex_y = get_tex_y_from_start(tex, col->line_height, y,
			clamp_draw_start(col));
	color = get_texel(tex, tex_x, tex_y);
	if (col->side == 1)
		color = (color >> 1) & 0x7F7F7F;
	return (color);
}
#else

int	get_shaded_color(const t_column *col, const t_image *tex, int tex_x, int y)
{
	int	color;
	int	tex_y;

	tex_y = get_tex_y_from_start(tex, col->line_height, y,
			clamp_draw_start(col));
	color = get_texel(tex, tex_x, tex_y);
	return (color);
}
#endif
