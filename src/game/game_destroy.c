/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:11:43 by csturny           #+#    #+#             */
/*   Updated: 2025/12/05 14:14:10 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Safely destroys an MLX image if both pointers are valid.
 * @param mlx Pointer to the MLX context.
 * @param img Pointer to the MLX image to destroy.
 *
 * Calls mlx_destroy_image only if both mlx and img are non-NULL.
 */
static void	safe_destroy_image(void *mlx, void *img)
{
	if (mlx && img)
		mlx_destroy_image(mlx, img);
}

/**
 * @brief Destroys all wall textures in the game.
 * @param g Pointer to the game state.
 *
 * Frees MLX images for each wall texture (north, south, east, west)
 * and sets their pointers to NULL.
 */
static void	destroy_textures(t_game *g)
{
	t_textures	*t;

	t = &g->world.tx;
	safe_destroy_image(g->mlx, t->no.img);
	safe_destroy_image(g->mlx, t->so.img);
	safe_destroy_image(g->mlx, t->ea.img);
	safe_destroy_image(g->mlx, t->we.img);
	t->no.img = NULL;
	t->so.img = NULL;
	t->ea.img = NULL;
	t->we.img = NULL;
}

/**
 * @brief Destroys all game resources and frees memory.
 * @param g Pointer to the game state.
 *
 * Destroys the frame image, all textures, the window, the MLX display,
 * and frees the MLX context and world data.
 */
void	game_destroy(t_game *g)
{
	if (!g)
		return ;
	safe_destroy_image(g->mlx, g->frame.img);
	destroy_textures(g);
	if (g->win && g->mlx)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	destroy_world(&g->world);
}

/**
 * @brief Closes the game window and exits the program.
 * @param g Pointer to the game state.
 * @return Always returns 0.
 *
 * Calls game_destroy to free all resources, then exits the program.
 */
int	close_window(t_game *g)
{
	game_destroy(g);
	exit(0);
	return (0);
}
