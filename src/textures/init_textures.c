#include "cub3d.h"


static int	load_texture(t_game *g, t_image *dst, const char *path)
{
	if (!path || *path == '\0')
		return (print_error("Texture path missing"));
	if (load_one_xpm(g, dst, path) < 0)
		return (print_error("Failed to load texture"));
	return (0);
}

int load_one_xpm(t_game *g, t_image *dst, const char *path)
{
    dst->img = mlx_xpm_file_to_image(g->mlx, (char *)path, &dst->w, &dst->h);
    if (!dst->img)
        return (-1);
    dst->addr = mlx_get_data_addr(dst->img, &dst->bpp, &dst->line_len, &dst->endian);
    return (dst->addr ? 0 : -1);
}
int	init_textures_from_paths(t_game *g)
{
	if (load_texture(g, &g->world.tx.no, g->world.paths.no) < 0)
		return (-1);
	if (load_texture(g, &g->world.tx.so, g->world.paths.so) < 0)
		return (-1);
	if (load_texture(g, &g->world.tx.we, g->world.paths.we) < 0)
		return (-1);
	if (load_texture(g, &g->world.tx.ea, g->world.paths.ea) < 0)
		return (-1);
	return (0);
}