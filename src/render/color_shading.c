/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:20:06 by csturny           #+#    #+#             */
/*   Updated: 2025/12/06 13:20:08 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
