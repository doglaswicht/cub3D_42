/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_columns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:04:54 by csturny           #+#    #+#             */
/*   Updated: 2025/12/05 15:05:23 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initializes the t_wall_vars structure for rendering a wall column.
 *
 * Computes and clamps the drawing bounds, texture X coordinate,
 * and prepares direct buffer access.
 * @param v Pointer to the structure to fill.
 * @param g Pointer to the game structure (frame buffer).
 * @param col Pointer to the column to render (raycasting info).
 * @param tex Pointer to the texture to use.
 */
static void	init_wall_vars(t_wall_vars *v, t_game *g, const t_column *col,
		const t_image *tex)
{
	if (col->draw_start < 0)
		v->start = 0;
	else
		v->start = col->draw_start;
	if (col->draw_end >= WIN_H)
		v->end = WIN_H - 1;
	else
		v->end = col->draw_end;
	v->tex_x = col->tex_x;
	if (v->tex_x < 0)
		v->tex_x = 0;
	if (v->tex_x >= tex->w)
		v->tex_x = tex->w - 1;
	v->y = v->start;
	v->pixels = (int *)g->frame.addr;
	v->line_len = g->frame.line_len / 4;
}

/**
 * @brief Draws a single wall column on the screen (vertical slice rendering).
 *
 * Uses direct buffer access for performance. Applies shading if enabled.
 * @param g Pointer to the game structure (frame buffer).
 * @param x Index of the column to draw (screen X coordinate).
 * @param col Pointer to the column to render (raycasting info).
 */
static void	render_wall_slice(t_game *g, int x, const t_column *col)
{
	t_wall_vars		v;
	int				color;
	const t_image	*tex;

	tex = get_tex_for_face(&g->world.tx, col->face);
	if (!tex || !tex->addr || col->line_height <= 0)
		return ;
	init_wall_vars(&v, g, col, tex);
	while (v.y <= v.end)
	{
		color = get_shaded_color(col, tex, v.tex_x, v.y);
		v.pixels[v.y * v.line_len + x] = color;
		v.y++;
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
