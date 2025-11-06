#include "cub3d.h"

static void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = img->addr
		+ (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

void	clear_frame(t_game *g, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			my_mlx_pixel_put(&g->frame, x, y, color);
			x++;
		}
		y++;
	}
}

void	render_frame(t_game *g)
{
	/* pour l’instant, juste un fond uni */
	clear_frame(g, 0x500000); // bleu sombre par exemple

	/* copie l’image dans la fenêtre */
	mlx_put_image_to_window(g->mlx, g->win, g->frame.img, 0, 0);
}
