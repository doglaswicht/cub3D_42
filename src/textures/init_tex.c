/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:47:39 by csturny           #+#    #+#             */
/*   Updated: 2025/11/16 13:48:21 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Loads a texture from a file path and stores it in the 
 * destination image.
 * @param g Pointer to the game state.
 * @param dst Pointer to the destination image structure.
 * @param path Path to the texture file.
 * @return 0 on success, or error code from print_error on failure.
 *
 * Checks the path, loads the XPM file, and handles errors.
 */
static int	load_texture(t_game *g, t_image *dst, const char *path)
{
	if (!path || *path == '\0')
		return (print_error("Texture path missing"));
	if (load_one_xpm(g, dst, path) < 0)
		return (print_error("Failed to load texture"));
	return (0);
}

/**
 * @brief Loads a single XPM texture file into an image structure.
 * @param g Pointer to the game state.
 * @param dst Pointer to the destination image structure.
 * @param path Path to the XPM file.
 * @return 0 on success, -1 on failure.
 *
 * Uses MiniLibX to load the image and retrieve its data address.
 */
int	load_one_xpm(t_game *g, t_image *dst, const char *path)
{
	dst->img = mlx_xpm_file_to_image(g->mlx, (char *)path,
			&dst->w, &dst->h);
	if (!dst->img)
		return (-1);
	dst->addr = mlx_get_data_addr(dst->img, &dst->bpp,
			&dst->line_len, &dst->endian);
	if (dst->addr)
		return (0);
	return (-1);
}

/**
 * @brief Loads all wall textures from their configured file paths.
 * @param g Pointer to the game state.
 * @return 0 on success, -1 on failure.
 *
 * Loads north, south, west, and east wall textures using load_texture.
 */
int	init_textures_from_paths(t_game *g)
{
	if (load_texture(g, &g->world.tx.no, g->world.paths.no) < 0)
		return (-1);
	if (load_texture(g, &g->world.tx.so, g->world.paths.so) < 0)
		return (-1);
	if (load_texture(g, &g->world.tx.we, g->world.paths.we) < 0)
		return (-1);
	if (load_texture(g, &g->world.tx.ea, g->world.paths.ea) < 0)
		return (-1);
	return (0);
}
