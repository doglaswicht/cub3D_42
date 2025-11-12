#include "cub3d.h"

// provisoir Debug
void	print_map(t_world *w)
{
	printf("[DEBUG] Map (%dx%d):\n", w->map_w, w->map_h);
	for (int y = 0; y < w->map_h; y++)
		printf("%s\n", w->map[y]);
	printf("\n");
}
