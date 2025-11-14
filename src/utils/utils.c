#include "cub3d.h"

void free_map(char **map, int h)
{
    int i = 0;
    if (!map)
        return;
    while (i < h)
    {
        if (map[i])
            free(map[i]);
        map[i] = NULL;
        i++;
    }
    free(map);
}


int	print_usage(void)
{
	write(2, "Usage: ./cub3d <map_file>\n", 27);
	return (1);
}

// --- util: clamp entier ---
int clampi(int value, int min, int max)
{
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}