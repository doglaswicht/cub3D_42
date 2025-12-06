/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:55:26 by csturny           #+#    #+#             */
/*   Updated: 2025/12/06 13:21:39 by csturny          ###   ########.fr       */
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
	return (*(unsigned int *)(tex->addr + ty * tex->line_len + tx * 4));
}
