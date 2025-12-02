/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:55:26 by csturny           #+#    #+#             */
/*   Updated: 2025/12/02 13:34:49 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Selects the correct wall texture based on the wall face.
 * @param tx Pointer to the textures structure containing all wall textures.
 * @param face Wall face identifier 
 * (FACE_NORTH, FACE_SOUTH, FACE_EAST, FACE_WEST).
 * @return Pointer to the corresponding t_image texture.
 *
 * Returns the texture for the given wall face (N, S, E, W).
 */
const t_image	*get_tex_for_face(const t_textures *tx, int face)
{
	if (face == FACE_NORTH)
		return (&tx->no);
	if (face == FACE_SOUTH)
		return (&tx->so);
	if (face == FACE_EAST)
		return (&tx->ea);
	return (&tx->we);
}

/**
 * @brief Reads a texel (pixel color) from a texture at coordinates (tx, ty).
 * @param tex Pointer to the texture image.
 * @param tx X coordinate in the texture.
 * @param ty Y coordinate in the texture.
 * @return The color value of the texel (unsigned int).
 *
 * Assumes the texture is 32 bits per pixel (ARGB or RGB).
 */
int	get_texel(const t_image *tex, int tx, int ty)
{
	char	*p;

	p = tex->addr + ty * tex->line_len + tx * (tex->bpp / 8);
	return (*(unsigned int *)p);
}

/**
 * @brief Computes the Y coordinate in the texture for a given screen pixel.
 * @param tex Pointer to the texture image.
 * @param line_height Height of the wall slice on screen.
 * @param y Current screen Y coordinate.
 * @param start Starting Y coordinate of the wall slice.
 * @return The clamped Y coordinate in the texture.
 *
 * Calculates the proportional Y position in the texture for 
 * vertical wall rendering.
 */
int	get_tex_y_from_start(const t_image *tex, int line_height, int y, int start)
{
	double	step;
	double	tex_pos0;
	double	tex_pos;
	int		tex_y;

	step = (double)tex->h / (double)line_height;
	tex_pos0 = (start - WIN_H / 2 + line_height / 2) * step;
	tex_pos = tex_pos0 + ((double)(y - start)*step);
	tex_y = (int)tex_pos;
	return (clampi(tex_y, 0, tex->h - 1));
}
