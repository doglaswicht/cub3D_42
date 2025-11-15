#include "cub3d.h"

double compute_wall_x(const t_game *g, const t_raycast *rc)
{
    double wall_x;
    double fraction;

    if (rc->side == 0)
        wall_x = g->player.pos.y + rc->perp_wall_dist * rc->raydir.y;
    else
        wall_x = g->player.pos.x + rc->perp_wall_dist * rc->raydir.x;
    fraction = wall_x - floor(wall_x);
    return fraction;
}

int compute_tex_x(const t_game *g, const t_raycast *rc, double wall_x, int face)
{
    const t_image *tex;
    int tx;
    
    tex = get_tex_for_face(&g->world.tx, face);
    tx = (int)(wall_x * (double)tex->w);
    if (rc->side == 0 && rc->raydir.x > 0)
        tx = tex->w - tx - 1;
    if (rc->side == 1 && rc->raydir.y < 0)
        tx = tex->w - tx - 1;
    return tx;
}