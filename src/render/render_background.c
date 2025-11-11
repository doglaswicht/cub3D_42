#include "cub3d.h"

void    render_background(t_game *g)
{
    int x;
    int y;
    int half_h;
    int ceil_color;
    int floor_color;

    half_h = WIN_H / 2;
    ceil_color = g->world.ceiling_color;
    floor_color = g->world.floor_color;
    y = 0;
    while (y < WIN_H)
    {
        x = 0;
        while (x < WIN_W)
        {
            if (y < half_h)
                my_mlx_pixel_put(&g->frame, x, y, ceil_color);
            else
                my_mlx_pixel_put(&g->frame, x, y, floor_color);
            x++;
        }
        y++;
    }
}
