/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:16:16 by csturny           #+#    #+#             */
/*   Updated: 2025/12/02 13:16:17 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	create_frame(t_game *g)
{
	g->frame.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
	if (!g->frame.img)
		return (1);
	g->frame.addr = mlx_get_data_addr(g->frame.img, &g->frame.bpp,
			&g->frame.line_len, &g->frame.endian);
	return (g->frame.addr == NULL);
}

int	init_images(t_game *g)
{
	if (create_frame(g))
		return (1);
	return (0);
}
