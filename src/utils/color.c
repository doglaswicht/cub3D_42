/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:36:35 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/16 21:37:35 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdint.h>

uint32_t	rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

uint32_t	shade(uint32_t color, double factor)
{
	int r = ((color >> 16) & 0xFF) * factor;
	int g = ((color >> 8) & 0xFF) * factor;
	int b = (color & 0xFF) * factor;

	if (r > 255) r = 255;
	if (g > 255) g = 255;
	if (b > 255) b = 255;

	return (r << 16) | (g << 8) | b;
}
