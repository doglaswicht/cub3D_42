/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:20:06 by csturny           #+#    #+#             */
/*   Updated: 2025/12/06 13:44:34 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Applies shading to a wall pixel color if needed.
 *
 * If shading is enabled and the wall side is vertical (side == 1),
 * the color is darkened to simulate shadow. Otherwise, the color is returned
 * unchanged.
 * @param color The original color value of the pixel.
 * @param side The wall side (1 for vertical, 0 for horizontal).
 * @return The possibly shaded color value.
 */
#ifdef ENABLE_SHADING

int	apply_shading(int color, int side)
{
	if (side == 1)
		return ((color >> 1) & 0x7F7F7F);
	return (color);
}
#else

int	apply_shading(int color, int side)
{
	(void)side;
	return (color);
}
#endif
