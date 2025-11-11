#include "cub3d.h"

static void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = img->addr
		+ (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

void	clear_frame(t_game *g, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			my_mlx_pixel_put(&g->frame, x, y, color);
			x++;
		}
		y++;
	}
}


void render_background(t_game *g)
{
	// plus tard : plafond/sol → pour l’instant, fond uni
	clear_frame(g, 0x500000); // bleu sombre par exemple
}

/*
// ici ce sera la final
void render_3d_view(t_game *g)
{
	(void)g;
	// ICI viendra ton raycasting (pour l’instant: on va viser 1 rayon au centre)
	// Définis la position de la colonne centrale :
	int x = WIN_W / 2;

	// Calcule la direction du rayon qui part du joueur vers cette colonne :
	double camera_x = 2.0 * x / (double)WIN_W - 1.0;  // transformer la position de la colonne (x) en une valeur entre -1 (gauche de l’écran) et +1 (droite de l’écran).
	t_vector raydir;
	
	raydir.x = g->player.dir.x + g->player.plane.x * camera_x;
	raydir.y = g->player.dir.y + g->player.plane.y * camera_x;
	
}*/






// provisoir juste pour un rayon étape 2 (fondation raycasting)
void render_central_ray_prov(t_game *g)
{
	t_raycast rc;

	// Rayon = direction du joueur (rayon central, donc aucun offset sur le plan)
	rc.raydir.x = g->player.dir.x;
	rc.raydir.y = g->player.dir.y;
	
	// Préparation DDA (cellule de départ, delta, step, side_dist)
	compute_dda_params(g, &rc);

	// Boucle DDA : trouver le mur
	run_dda(g, &rc);

	// Pour le debug : afficher la direction
	printf("Ray central dir = (%.2f, %.2f)\n", rc.raydir.x, rc.raydir.y);
}


void render_frame(t_game *g)
{
	render_background(g);
	//render_3d_view(g);
	render_central_ray_prov(g);
	mlx_put_image_to_window(g->mlx, g->win, g->frame.img, 0, 0);
}

// fonction provisoir
// Cette fonction sert à dessiner une bande verticale (une colonne de pixels) dans ton image MLX, entre deux Y, à la position X.
void	draw_vertical_line(t_game *g, int x, int y_start, int y_end, int color)
{
	int	y;

	if (x < 0 || x >= WIN_W)
		return;
	if (y_start < 0)
		y_start = 0;
	if (y_end >= WIN_H)
		y_end = WIN_H - 1;
	y = y_start;
	while (y <= y_end)
	{
		my_mlx_pixel_put(&g->frame, x, y, color);
		++y;
	}
}