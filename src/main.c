/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:27:45 by dleite-b          #+#    #+#             */
/*   Updated: 2025/10/21 20:47:16 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int close_window(t_game *game)
{
    if(game->mlx && game->win)
        mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}

int main(int argc, char **argv)
{
    t_game  game;

    if(argc != 2)
    {
        printf("Error:\nUsage: ./cub3D <map.cub>\n");
        return(-1);
    }
    if(init_game(&game, argv[1]) == -1)
        return(1);
    // pintan o fundo
	for (int y = 0; y < 600; y++)
	{
		for (int x = 0; x < 800; x++)
		{
			if (y < 300)
				my_mlx_pixel_put(&game.img, x, y, 0x87CEEB); // white blue (sky)
			else
				my_mlx_pixel_put(&game.img, x, y, 0x228B22); // gren (chão)
		}
	}

// Copiar imagem para janela
mlx_put_image_to_window(game.mlx, game.win, game.img.img, 0, 0);
mlx_loop(game.mlx);

   /* mlx_hook(game.win, 17, 0, close_window, &game);
    mlx_loop(game.mlx);*/
    return (0);
}
/*
#include "mlx.h"
#include <stdlib.h>

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    if (!mlx)
        return (1);
    win = mlx_new_window(mlx, 800, 600, "cub3D test");
    if (!win)
        return (1);

    // Colocar um pixel vermelho no centro
    mlx_pixel_put(mlx, win, 400, 300, 0xFF0000);
    mlx_pixel_put(mlx, win, 800, 600, 0xFF0000);
    mlx_pixel_put(mlx, win, 300, 200, 0xFF0000);
    mlx_pixel_put(mlx, win, 400, 300, 0xFF0000);

    mlx_loop(mlx);
    return (0);
}
*/