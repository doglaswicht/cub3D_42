#include "cub3d.h"


static int	choose_color(const t_column *col)
{
	if (col->face == FACE_NORTH)
		return (0xFF0000); // Nord = rouge
	if (col->face == FACE_SOUTH)
		return (0x00FF00); // Sud = vert
	if (col->face == FACE_EAST)
		return (0x0000FF); // Est = bleu
	return (0xFFFF00); // Ouest = jaune
}



// dessine UNE bande verticale (une “slice” de mur) à la colonne x
// je sais dessiner UNE seule bande de mur!!!
static void render_wall_slice(t_game *g, int x, const t_column *col)
{
    int y;
    int start;
    int end;
    int color;

    start = col->draw_start;
    if (start < 0)
        start = 0;
    end = col->draw_end;
    if (end >= WIN_H)
        end = WIN_H - 1;
    
    color = choose_color(col); // ou 0xFF0000 si tu veux encore du rouge
   
    y = start;
    while (y <=end)
    {
		my_mlx_pixel_put(&g->frame, x, y, color);
		y++;
	}
}


// dessine TOUS les murs (toutes les colonnes)
// je boucle sur tout l'écran en X!!!
void    render_walls(t_game *g, const t_column cols[WIN_W])
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		render_wall_slice(g, x, &cols[x]);
		x++;
	}
}



