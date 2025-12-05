/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:16:16 by csturny           #+#    #+#             */
/*   Updated: 2025/12/05 14:23:26 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Creates the main frame image for rendering.
 * @param g Pointer to the game state.
 * @return 0 on success, 1 on error.
 *
 * Allocates a new MLX image for the frame, sets its dimensions,
 * and retrieves the image data address. Returns 1 if allocation fails.
 */
static int	create_frame(t_game *g)
{
	g->frame.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
	if (!g->frame.img)
		return (1);
	g->frame.w = WIN_W;
	g->frame.h = WIN_H;
	g->frame.addr = mlx_get_data_addr(g->frame.img, &g->frame.bpp,
			&g->frame.line_len, &g->frame.endian);
	return (g->frame.addr == NULL);
}

/**
 * @brief Initializes all images needed for rendering.
 * @param g Pointer to the game state.
 * @return 0 on success, 1 on error.
 *
 * Calls create_frame to allocate the main frame image.
 */
int	init_images(t_game *g)
{
	if (create_frame(g))
		return (1);
	return (0);
}
