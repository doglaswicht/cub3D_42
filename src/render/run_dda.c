#include "cub3d.h"

void run_dda(const t_game *g, t_raycast *rc)
{
    // à remplir!!!
    int hit;

    hit = 0;
    while (!hit)
    {
        if (rc->side_dist.x < rc->side_dist.y)
        {
            rc->side_dist.x += rc->delta_dist.x;
            rc->map.x += rc->step_x;
            rc->side = 0; // mur vertical, le rayon a traversé une ligne verticale (mur est/oust)
        }
        else
        {
            rc->side_dist.y += rc->delta_dist.y;
            rc->map.y += rc->step_y;
            rc->side = 1; // mur horizontal. e rayon a traversé une ligne horizontal(mur sud/nord)
        }

        // Sécurité : si le rayon sort de la map, on arrête
		if (rc->map.x < 0 || rc->map.x >= g->world.map_w
			|| rc->map.y < 0 || rc->map.y >= g->world.map_h)
			break;

        // ici le Test de collision avec un mur
        if (g->world.map[(int)rc->map.y][(int)rc->map.x] == '1')
			hit = 1;
        //printf("Debug - Step: map=(%.0f,%.0f) side=%d\n", rc->map.x, rc->map.y, rc->side);
    }
}


void    compute_perp_distance(const t_game *g, t_raycast *rc)
{
    if (rc->side == 0)
    {
        rc->perp_wall_dist = (rc->map.x - g->player.pos.x + (1 - rc->step_x) / 2.0) / rc->raydir.x;
    }
    else
    {
        rc->perp_wall_dist = (rc->map.y - g->player.pos.y + (1 - rc->step_y) / 2.0) / rc->raydir.y;
    }
    // ici pas compris a quoi ça sert
    if (rc->perp_wall_dist <= 0.0)
        rc->perp_wall_dist = 0.0001;
}

void    compute_wall_height(t_raycast *rc)
{
    // hauteur projeté en fonctin de dist. au mur
    rc->line_height = (int)(WIN_H / rc->perp_wall_dist);

    // déterminer les postion de début/fin sur l'écran
    rc->draw_start = -rc->line_height / 2 + WIN_H / 2;
    if (rc->draw_start < 0)
        rc->draw_start = 0;

    rc->draw_end = rc->line_height / 2 + WIN_H / 2;
    if (rc->draw_end >= WIN_H)
        rc->draw_end = WIN_H - 1;
}