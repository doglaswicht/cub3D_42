#include "cub3d.h"
#include "debug.h"


// toute la frame.
/**
 * @brief Renders the entire frame: background, walls, and displays it.
 * @param g Pointer to the game state.
 */
/*
void	render_frame(t_game *g)
{
	t_column cols[WIN_W];
	

	render_background(g);
	cast_rays(g, cols);
	render_walls(g, cols);
	mlx_put_image_to_window(g->mlx, g->win, g->frame.img, 0, 0);
}*/

// ci dessous la fonction debug
void	render_frame(t_game *g)
{
    t_column cols[WIN_W];
    t_raycast rc_debug[5];
    int idx[5] = {0, WIN_W/4, WIN_W/2, 3*WIN_W/4, WIN_W-1};

    render_background(g);
    cast_rays(g, cols, rc_debug, idx, 5);
    static int done = 0;
    if (!done) {
        done = 1;
        printf("\n==== DEBUG 5 COLONNES ====\n");
        debug_dump_column_table((const t_column[]){cols[idx[0]], cols[idx[1]], cols[idx[2]], cols[idx[3]], cols[idx[4]]}, idx);
        debug_dump_raycast_table(rc_debug, idx);
        printf("=========================\n\n");
    }
    debug_faces_once(cols);
    render_walls(g, cols);
    mlx_put_image_to_window(g->mlx, g->win, g->frame.img, 0, 0);
}
