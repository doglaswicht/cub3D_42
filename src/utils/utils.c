#include "cub3d.h"


void free_map(char **map, int h)
{
	if (!map) return;
	for (int i = 0; i < h; i++)
		free(map[i]);
	free(map);
}


int	print_usage(void)
{
	write(2, "Usage: ./cub3d <map_file>\n", 27);
	return (1);
}