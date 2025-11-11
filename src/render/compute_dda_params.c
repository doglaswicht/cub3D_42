#include "cub3d.h"

static void	init_ray_map(const t_game *g, t_raycast *rc)
{
	rc->map.x = (int)g->player.pos.x;
	rc->map.y = (int)g->player.pos.y;
}

static void	compute_delta_dist(t_raycast *rc)
{
	if (rc->raydir.x == 0)
		rc->delta_dist.x = 1e30;
	else
		rc->delta_dist.x = fabs(1.0 / rc->raydir.x);
	if (rc->raydir.y == 0)
		rc->delta_dist.y = 1e30;
	else
		rc->delta_dist.y = fabs(1.0 / rc->raydir.y);
}

static void	init_step_and_side_dist(const t_game *g, t_raycast *rc)
{
	if (rc->raydir.x < 0)
	{
		rc->step_x= -1;
		rc->side_dist.x = (g->player.pos.x - rc->map.x) * rc->delta_dist.x;
	}
	else
	{
		rc->step_x= 1;
		rc->side_dist.x = (rc->map.x + 1.0 - g->player.pos.x) * rc->delta_dist.x;
	}
	if (rc->raydir.y < 0)
	{
		rc->step_y= -1;
		rc->side_dist.y = (g->player.pos.y - rc->map.y) * rc->delta_dist.y;
	}
	else
	{
		rc->step_y= 1;
		rc->side_dist.y = (rc->map.y + 1.0 - g->player.pos.y) * rc->delta_dist.y;
	}
}


void	compute_dda_params(const t_game *g, t_raycast *rc)
{
	init_ray_map(g, rc);
	compute_delta_dist(rc);
	init_step_and_side_dist(g, rc);
}