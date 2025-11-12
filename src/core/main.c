#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	if (ac != 2)
		return (print_usage(), 1);

	if (game_init(&g, av[1]) != 0)
		return (1);

	game_run(&g);
	return (0);
}
