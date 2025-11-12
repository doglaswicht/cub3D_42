
#include "cub3d.h"


/**
 * @brief Sets a pixel in the image buffer at (x, y) with the given color.
 * @param img Pointer to the image structure.
 * @param x X coordinate (horizontal position).
 * @param y Y coordinate (vertical position).
 * @param color Color value (ARGB or RGB).
 */
void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = img->addr
		+ (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

/**
 * @brief Clears the entire frame buffer with a single color.
 * @param g Pointer to the game state.
 * @param color Color value to fill the frame.
 */
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