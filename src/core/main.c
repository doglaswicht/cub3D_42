#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	g;

	if (ac != 2)
		return (print_usage(), 1);

	   if (game_init(&g, av[1]) != 0) // patie a Doglas
		   return (1);

	   game_run(&g); // ici commence mon Render moteur 3d
	return (0);
}
