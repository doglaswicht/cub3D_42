/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:08:44 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/20 01:01:13 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	finalize_parse(t_world *w, t_parse_state *state)
{
	if (!w->paths.no || !w->paths.so || !w->paths.we || !w->paths.ea)
		return (print_error("Missing texture definition"));
	if (w->floor_color == -1 || w->ceiling_color == -1)
		return (print_error("Missing floor or ceiling color"));
	if (!w->map || state->map_lines == 0)
		return (print_error("Map section missing"));
	if (find_player_spawn(w) == -1)
		return (-1);
	if (validate_map(w) == -1)
		return (-1);
	return (0);
}

void	initialize_parse_lines(void)
{
	
}
static	int	parse_lines(int fd, t_world *world)
{
	t_parse_state	state;
	int				error;
	char			*line;
	int				status;
	size_t			len;

	state.map_started = 0;
	state.map_finished = 0;
	state.map_lines = 0;
	state.max_width = 0;
	error = 0;
	while (1)
	{
		line = read_line(fd, &error);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		status = parse_line(line, world, &state);
		free(line);
		if (status == -1)
			return (-1);
	}
	if (error)
		return (print_error("Failed to read .cub file"));
	return (finalize_parse(world, &state));
}

int	parse_cub(char *path, t_game *game)
{
	int	fd;
	int	status;

	if (!path || !game)
		return (print_error("Invalid arguments for parse_cub"));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (print_error("Cannot open .cub file"));
	status = parse_lines(fd, &game->world);
	close(fd);
	if (status == -1)
		game_destroy(game);
	return (status);
}
