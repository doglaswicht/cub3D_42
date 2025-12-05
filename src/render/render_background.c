/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:38:44 by csturny           #+#    #+#             */
/*   Updated: 2025/12/05 13:27:47 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Renders the background (ceiling and floor) for the entire frame.
 * @param g Pointer to the game state.
 *
 * Fills the top half of the frame with the ceiling color 
 * and the bottom half with the floor color.
 */
/*
void	render_background(t_game *g)
{
	int	x;
	int	y;
	int	half_h;
	int	ceil_color;
	int	floor_color;

	half_h = WIN_H / 2;
	ceil_color = g->world.ceiling_color;
	floor_color = g->world.floor_color;
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			if (y < half_h)
				my_mlx_pixel_put(&g->frame, x, y, ceil_color);
			else
				my_mlx_pixel_put(&g->frame, x, y, floor_color);
			x++;
		}
		y++;
	}
}*/


static void	fill_row(int *row, int w, int color)
{
	int x = 0;
	while (x < w)
	{
		row[x] = color;
		x++;
	}
}



void render_background(t_game *g)
{
	t_bg_vars v;

	v.pixels = (int *)g->frame.addr;
	v.line_len = g->frame.line_len / 4;
	v.half_h = g->frame.h / 2;

	v.y = 0;
	while (v.y < v.half_h)
	{
		fill_row(v.pixels + v.y * v.line_len, g->frame.w, g->world.ceiling_color);
		v.y++;
	}
	v.y = v.half_h;
	while (v.y < g->frame.h)
	{
		fill_row(v.pixels + v.y * v.line_len, g->frame.w, g->world.floor_color);
		v.y++;
	}
}
