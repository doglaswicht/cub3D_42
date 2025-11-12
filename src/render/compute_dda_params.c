#include "cub3d.h"


/**
 * @brief Calculates the distance the ray must travel to cross one grid square in X and Y directions.
 * @param rc Pointer to the raycasting structure (input/output).
 *
 * Sets delta_dist.x and delta_dist.y, which represent how far the ray must move along its path
 * to go from one vertical (X) or horizontal (Y) grid line to the next. These values are used
 * in the DDA loop to incrementally step through the map grid.
 *
 * - If the ray direction is zero in an axis, sets a very large value to avoid division by zero.
 * - Otherwise, uses the absolute value of the inverse of the ray direction for that axis.
 */
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

/**
 * @brief Computes the step direction and initial side distances for the DDA algorithm.
 * @param g Pointer to the game state.
 * @param rc Pointer to the raycasting structure (input/output).
 *
 * Determines whether the ray will step forward (+1) or backward (-1) in X and Y directions
 * based on the ray direction. Calculates the initial distance from the player's position
 * to the first grid boundary in both axes, which is needed to start the DDA loop.
 *
 * - step_x/step_y: +1 if the ray moves right/down, -1 if left/up.
 * - side_dist.x/side_dist.y: distance from the player to the next vertical/horizontal grid line.
 */
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

/**
 * @brief Initializes DDA parameters for raycasting (delta distances, steps, and initial side distances).
 * @param g Pointer to the game state.
 * @param rc Pointer to the raycasting structure (input/output).
 *
 * Prepares all values needed for the DDA loop, including step direction and initial distances to the next grid lines.
 */
void	compute_dda_params(const t_game *g, t_raycast *rc)
{
	compute_delta_dist(rc);
	init_step_and_side_dist(g, rc);
}