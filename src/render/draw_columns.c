/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_columns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:04:54 by csturny           #+#    #+#             */
/*   Updated: 2025/12/06 14:20:06 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initializes the t_wall_vars structure for rendering a wall column.
 *
 * Sets the drawing bounds, clamps the texture X coordinate,
 * and prepares direct buffer access and texture mapping parameters.
 * @param v Pointer to the t_wall_vars structure to initialize.
 * @param g Pointer to the game structure (contains the frame buffer).
 * @param col Pointer to the column to render (raycasting info).
 * @param tex Pointer to the texture to use for this wall column.
 */
static void	init_wall_vars(t_wall_vars *v, t_game *g, const t_column *col,
		const t_image *tex)
{
	if (col->draw_wall_y_star < 0)
		v->wall_col_start = 0;
	else
		v->wall_col_start = col->draw_wall_y_star;
	if (col->draw_wall_y_star >= WIN_H)
		v->wall_col_end = WIN_H - 1;
	else
		v->wall_col_end = col->draw_wall_y_end;
	v->tex_x_index = col->tex_x;
	if (v->tex_x_index < 0)
		v->tex_x_index = 0;
	if (v->tex_x_index >= tex->w)
		v->tex_x_index = tex->w - 1;
	v->current_y_row = v->wall_col_start ;
	v->pixels_buffer = (int *)g->frame.addr;
	v->pixels_per_row = g->frame.line_len / 4;
	v->tex_y_scaling = (double)tex->h / (double)col->line_height;
	v->tex_y_position = (v->wall_col_start - WIN_H / 2 + col->line_height / 2)
		* v->tex_y_scaling;
}

/**
 * @brief Draws a single wall column on the screen (vertical slice rendering).
 *
 * Uses direct buffer access for performance. For each pixel in the column,
 * computes the corresponding texture Y coordinate, fetches the texel,
 * applies shading if needed, and writes the color to the frame buffer.
 * @param g Pointer to the game structure (frame buffer).
 * @param x Index of the column to draw (screen X coordinate).
 * @param col Pointer to the column to render (raycasting info).
 */
static void	render_wall_slice(t_game *g, int x, const t_column *col)
{
	t_wall_vars		v;
	const t_image	*current_wall_tex;
	int				tex_y_index;
	int				color;

	current_wall_tex = get_tex_for_face(&g->world.tx, col->face);
	if (!current_wall_tex || !current_wall_tex->addr || col->line_height <= 0)
		return ;
	init_wall_vars(&v, g, col, current_wall_tex);
	while (v.current_y_row <= v.wall_col_end)
	{
		tex_y_index = (int)v.tex_y_position;
		color = get_texel(current_wall_tex, v.tex_x_index, tex_y_index);
		color = apply_shading(color, col->side);
		v.pixels_buffer[v.current_y_row * v.pixels_per_row + x] = color;
		v.tex_y_position += v.tex_y_scaling;
		v.current_y_row++;
	}
}

/**
 * @brief Draws all wall columns on the screen (main rendering loop).
 *
 * Loops over the entire window width and calls render_wall_slice 
 * for each column.
 * @param g Pointer to the game structure (frame buffer).
 * @param cols Array of columns to render (size WIN_W).
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
