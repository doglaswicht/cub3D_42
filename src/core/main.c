#include "cub3d.h"

int	is_cub_file(char *path)
{
	const char *dot = ft_strrchr(path, '.');
	if(!dot)
		return (0);
	return (ft_strncmp(dot + 1, "cub", 4) == 0);
}


int	main(int ac, char **av)
{
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	if (ac != 2)
		return (print_usage(), 1);
	if(!is_cub_file(av[1]))
		return (print_usage(), 1);
	if (game_init(&g, av[1]) != 0)
		return (1);

	game_run(&g);

	return (0);
}
