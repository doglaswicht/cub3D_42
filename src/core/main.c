#include "cub3d.h"



int	close_window(t_game *g)
{
	game_destroy(g);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	g;

	if (ac != 2)
		return (print_usage(), 1);

	if (game_init(&g, av[1]) != 0)
		return (1);

	game_run(&g);
	game_destroy(&g);
	return (0);
}
