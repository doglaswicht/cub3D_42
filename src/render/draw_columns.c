/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_columns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:39:21 by csturny           #+#    #+#             */
/*   Updated: 2025/11/18 15:35:15 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Renders a vertical wall slice for a given column.
 * @param g Pointer to the game state.
 * @param x X coordinate of the column on the screen.
 * @param col Pointer to the column rendering info.
 *
 * Draws the wall segment for the column using texture mapping and shading.
 * Selects the correct texture, clamps coordinates, and draws each pixel.
 */
static void	render_wall_slice(t_game *g, int x, const t_column *col)
{
	const t_image	*tex;
	int				start;
	int				end;
	int				tex_x;
	int				y;

	tex = get_tex_for_face(&g->world.tx, col->face);
	if (!tex || !tex->addr || col->line_height <= 0)
		return ;
	start = clamp_draw_start(col);
	end = clamp_draw_end(col);
	tex_x = clamp_tex_x(col, tex);
	y = start;
	while (y <= end)
	{
		my_mlx_pixel_put(&g->frame, x, y,
			get_shaded_color(col, tex, tex_x, y));
		y++;
	}
}

/**
 * @brief Renders a vertical wall slice for a given column.
 * @param g Pointer to the game state.
 * @param col Pointer to the column rendering info.
 *
 * Draws the wall segment for the column using texture mapping or solid color.
 */

/*
static void render_wall_slice(t_game *g, int x, const t_column *col)
{
	const t_image *tex = get_tex_for_face(&g->world.tx, col->face);
	if (!tex || !tex->addr || col->line_height <= 0)
		return;

	int start;
	int end;
	int tex_x;
	int y;

	if (col->draw_start < 0)
		start = 0;
	else
		start = col->draw_start;

	if (col->draw_end >= WIN_H)
		end = WIN_H - 1;
	else
		end = col->draw_end;

	tex_x = col->tex_x;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->w)
		tex_x = tex->w - 1;

	y = start;
	while (y <= end)
	{
		int tex_y = get_tex_y_from_start(tex, col->line_height, y, start);
		int color = get_texel(tex, tex_x, tex_y);
		if (col->side == 1)
			color = (color >> 1) & 0x7F7F7F; // ici shading 
		my_mlx_pixel_put(&g->frame, x, y, color);
		y++;
	}
}*/

/**
 * @brief Draws all wall columns for the current frame.
 * @param g Pointer to the game state.
 * @param cols Array of column rendering info (size WIN_W).
 *
 * Iterates over all columns and calls render_wall_slice for each.
 */
void	render_walls(t_game *g, const t_column cols[WIN_W])
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		render_wall_slice(g, x, &cols[x]);
		x++;
	}
}
