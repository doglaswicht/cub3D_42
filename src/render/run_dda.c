#include "cub3d.h"

/**
 * @brief Performs the DDA (Digital Differential Analyzer) algorithm to find the first wall hit by the ray.
 * @param g Pointer to the game state.
 * @param rc Pointer to the raycasting structure (input/output).
 *
 * Steps through the map grid until a wall ('1') is hit, updating the raycasting info.
 */
void run_dda(const t_game *g, t_raycast *rc)
{
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

