#include "cub3d.h"




// A recoder!!!!
// --- dessine UNE slice de mur à la colonne x ---
/**
 * @brief Renders a vertical wall slice for a given column.
 * @param g Pointer to the game state.
 * @param col Pointer to the column rendering info.
 *
 * Draws the wall segment for the column using texture mapping or solid color.
 */
static void render_wall_slice(t_game *g, int x, const t_column *col)
{
    const t_image *tex = get_tex_for_face(&g->world.tx, col->face);
    if (!tex || !tex->addr || col->line_height <= 0)
        return;

    int start;
    int end;
    int tex_x;
    int y;

    if (col->draw_start < 0)
        start = 0;
    else
        start = col->draw_start;

    if (col->draw_end >= WIN_H)
        end = WIN_H - 1;
    else
        end = col->draw_end;

    tex_x = col->tex_x;
    if (tex_x < 0)
        tex_x = 0;
    if (tex_x >= tex->w)
        tex_x = tex->w - 1;

    y = start;
    while (y <= end)
    {
        int tex_y = get_tex_y_from_start(tex, col->line_height, y, start);
        int color = get_texel(tex, tex_x, tex_y);
        //if (col->side == 1)
            //color = (color >> 1) & 0x7F7F7F; // ici shading 
        my_mlx_pixel_put(&g->frame, x, y, color);
        y++;
    }
}


// dessine TOUS les murs (toutes les colonnes)
// je boucle sur tout l'écran en X!!!
/**
 * @brief Draws all wall columns for the current frame.
 * @param g Pointer to the game state.
 * @param cols Array of column rendering info (size WIN_W).
 *
 * Iterates over all columns and calls render_wall_slice for each.
 */
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



