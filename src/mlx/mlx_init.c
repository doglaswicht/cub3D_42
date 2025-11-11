#include "cub3d.h"
// But : Initialiser la connexion à la librairie graphique MiniLibX et créer la fenêtre principale du jeu.
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

//But : Créer une image (buffer) en mémoire pour dessiner chaque frame avant de l’afficher dans la fenêtre.
//image (buffer) en mémoire :zone de la mémoire (un tableau de pixels) où tu dessines toute la scène avant de l’afficher à l’écran.
// Tu ne dessines pas directement sur la fenêtre : tu “prépares” l’image dans ce buffer, puis tu l’envoies d’un coup à la fenêtre (avec mlx_put_image_to_window).
/*
Comment ça marche ?

Tu crées une image en mémoire avec mlx_new_image.
Tu récupères l’adresse du buffer (tableau de pixels) avec mlx_get_data_addr.
Tu dessines dessus (avec ta fonction my_mlx_pixel_put).
Quand tout est prêt, tu affiches l’image dans la fenêtre avec mlx_put_image_to_window.
*/

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
