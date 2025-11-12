#include "cub3d.h"


/**
 * @brief Fills basic column rendering info from raycasting results.
 * @param col Pointer to the column structure to fill.
 * @param rc Pointer to the raycasting result structure.
 */
void	fill_column_basic(t_column *col, const t_raycast *rc)
{
	col->perp_dist = rc->perp_wall_dist;
	col->line_height = rc->line_height;
	col->draw_start = rc->draw_start;
	col->draw_end = rc->draw_end;
	col->side = rc->side;
}


/**
 * @brief Fills texture-related info for a column from raycasting results.
 * @param g Pointer to the game state.
 * @param col Pointer to the column structure to fill.
 * @param rc Pointer to the raycasting result structure.
 */
void fill_column_tex(const t_game *g, t_column *col, const t_raycast *rc)
{
    col->face = get_face(rc);
    col->wall_x = compute_wall_x(g, rc);
    col->tex_x = compute_tex_x(g, rc, col->wall_x, col->face);
}