/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:16:43 by csturny           #+#    #+#             */
/*   Updated: 2025/12/05 14:24:01 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Sets MLX and window pointers to NULL in the game state.
 * @param g Pointer to the game state.
 *
 * Initializes the MLX and window pointers to NULL before allocation.
 */
static void	set_null_mlx(t_game *g)
{
	g->mlx = NULL;
	g->win = NULL;
}

/**
 * @brief Initializes the MLX context and creates the main window.
 * @param g Pointer to the game state.
 * @return 0 on success, 1 on error.
 *
 * Allocates the MLX context and window. Returns 1 if allocation fails.
 */
int	init_mlx(t_game *g)
{
	set_null_mlx(g);
	g->mlx = mlx_init();
	if (!g->mlx)
		return (1);
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "cub3D");
	if (!g->win)
		return (1);
	return (0);
}
