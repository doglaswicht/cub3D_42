#include "cub3d.h"


// provisoir DEBUG
static void	print_color_rgb(int color)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	printf("RGB = (%3d, %3d, %3d)\n", r, g, b);
}


// provisoir DEBUG
void	print_world_debug(const t_world *w)
{
	printf("[DEBUG] World info:\n");
	printf("  Map size     : %d x %d\n", w->map_w, w->map_h);
	printf("  Ceiling color: 0x%06X ", w->ceiling_color);
	print_color_rgb(w->ceiling_color);
	printf("  Floor color  : 0x%06X ", w->floor_color);
	print_color_rgb(w->floor_color);
	printf("  Spawn:\n");
	printf("    pos   = (%.2f, %.2f)\n", w->spawn.pos.x, w->spawn.pos.y);
	printf("    dir   = (%.2f, %.2f)\n", w->spawn.dir.x, w->spawn.dir.y);
	printf("    plane = (%.2f, %.2f)\n", w->spawn.plane.x, w->spawn.plane.y);
}
