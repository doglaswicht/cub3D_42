#include "cub3d.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
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





/*
// provisoir juste pour un rayon étape 2 (fondation raycasting)
void render_central_ray_prov(t_game *g)
{
	t_raycast rc;

	ft_bzero(&rc, sizeof(t_raycast));   // sécurité

	// Rayon = direction du joueur (rayon central, donc aucun offset sur le plan)
	rc.raydir.x = g->player.dir.x;
	rc.raydir.y = g->player.dir.y;
	
	// Préparation DDA (cellule de départ, delta, step, side_dist)
	compute_dda_params(g, &rc);

	// Boucle DDA : trouver le mur
	run_dda(g, &rc);

	// Correction "distance du rayon", éviter l'effet fish-eye
	// Calculer la distance perpendiculaire au mur
	compute_perp_distance(g, &rc);

	// Calculer la hauteur du mur projeté (dépend de la dist. au mur)
	compute_wall_height(&rc);

	// dessiner une bande vertical au centre
	int color = (rc.side == 0) ? 0xFF0000 : 0x880000; // rouge ou rouge foncé
	draw_vertical_line(g, WIN_W / 2, rc.draw_start, rc.draw_end, color);

	// Pour le debug :
	printf("Ray central dir = (%.2f, %.2f), dist=%.3f, start=%d, end=%d\n",
        rc.raydir.x, rc.raydir.y, rc.perp_wall_dist,
        rc.draw_start, rc.draw_end);
}*/

/*
// remplace le void render_central_ray_prov(t_game *g)
// ici passe de 1 rayon à tous les pixels écran
void render_3d_view(t_game *g)
{
	int x;
	t_raycast rc;
	double	camera_x;
	int color;

	x = 0;
	while (x < WIN_W)
	{
		// de -1 à 1 sur l'écran (gauche à droite)
		camera_x = 2.0 * x / (double)WIN_W - 1.0;

		ft_bzero(&rc, sizeof(t_raycast));   // sécurité

		// Direction du rayon pour la colone x
		// ou dir: direction du joueur (au centre du FOV)
		// ou plane: vecteur "camera" perpendiculaire à dir
		// Donc raydir = dir + plane * camera_x -> rayon pour la colonne x!
		rc.raydir.x = g->player.dir.x + g->player.plane.x * camera_x;
		rc.raydir.y = g->player.dir.y + g->player.plane.y * camera_x;
		
		// Préparation DDA (cellule de départ, delta, step, side_dist)
		compute_dda_params(g, &rc);

		// Boucle DDA : trouver le mur
		run_dda(g, &rc);

		// Correction "distance du rayon", éviter l'effet fish-eye
		// Calculer la distance perpendiculaire au mur
		compute_perp_distance(g, &rc);

		// Calculer la hauteur du mur projeté (dépend de la dist. au mur)
		compute_wall_height(&rc);

		// dessiner à la colonne x!
		color = (rc.side == 0) ? 0xFF0000 : 0x880000; // rouge ou rouge foncé
		draw_vertical_line(g, x, rc.draw_start, rc.draw_end, color);

		// incrémentaiton 
		x++;
	}
}
*/

static void	fill_column_basic(t_column *col, const t_raycast *rc)
{
	col->perp_dist = rc->perp_wall_dist;
	col->line_height = rc->line_height;
	col->draw_start = rc->draw_start;
	col->draw_end = rc->draw_end;
	col->side = rc->side;
	col->face = get_face(rc);
    // col->face, col->wall_x, col->tex_x seront remplis plus tard
}


static void init_raycast(t_raycast *rc, int x, const t_game *g)
{
    double camera_x;

    // de -1 à 1 sur l'écran (gauche à droite)
    camera_x = 2.0 * x / (double)WIN_W - 1.0;

    ft_bzero(rc, sizeof(t_raycast));   // sécurité, remet tout à 0

    rc->raydir.x = g->player.dir.x + g->player.plane.x * camera_x;
    rc->raydir.y = g->player.dir.y + g->player.plane.y * camera_x;

    rc->map.x = (int)g->player.pos.x;
    rc->map.y = (int)g->player.pos.y;
}

// calcule les rayons.
// calcule les rayons.
void    cast_rays(const t_game *g, t_column cols[WIN_W])
{
    int         x;
    t_raycast   rc;

    x = 0;
    while (x < WIN_W)
    {
        // init
        init_raycast(&rc, x, g);

        // Préparation DDA (cellule de départ, delta, step, side_dist)
        compute_dda_params(g, &rc);

        // Boucle DDA : trouver le mur
        run_dda(g, &rc);

        // Correction "distance du rayon", éviter l'effet fish-eye
        compute_perp_distance(g, &rc);

        // Calculer la hauteur du mur projeté
        compute_wall_height(&rc);

        // remplir les colonnes
        fill_column_basic(&cols[x], &rc);
        x++;
    }
}




// toute la frame.
void render_frame(t_game *g)
{
	t_column cols[WIN_W];

	render_background(g);          // ciel + sol
	//render_3d_view(g);
	//render_central_ray_prov(g);
	cast_rays(g, cols); // calcule toutes les colonnes (raycasting)
	render_walls(g, cols); // dessine toutes les colonnes
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