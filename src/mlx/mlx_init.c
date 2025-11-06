#include "cub3d.h"

int	init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
	{
		write(2, "Error: mlx_init failed\n", 23);
		return (1);
	}
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "Cub3D");
	if (!g->win)
	{
		write(2, "Error: mlx_new_window failed\n", 29);
		return (1);
	}
	return (0);
}

int	init_images(t_game *g)
{
	g->frame.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
	if (!g->frame.img)
	{
		write(2, "Error: mlx_new_image failed\n", 28);
		return (1);
	}
	g->frame.addr = mlx_get_data_addr(
			g->frame.img,
			&g->frame.bpp,
			&g->frame.line_len,
			&g->frame.endian);
	if (!g->frame.addr)
	{
		write(2, "Error: mlx_get_data_addr failed\n", 32);
		return (1);
	}
	return (0);
}
