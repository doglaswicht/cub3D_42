/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 01:05:20 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/05 11:28:56 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* --------------------------- FINALIZE PARSE --------------------------- */

static int	finalize_parse(t_world *w, t_parse_state *state)
{
	if (!w->paths.no || !w->paths.so || !w->paths.we || !w->paths.ea)
		return (print_error("Missing texture definition"));
	if (w->floor_color == -1 || w->ceiling_color == -1)
		return (print_error("Missing floor or ceiling color"));
	if (!w->map || state->map_lines == 0)
		return (print_error("Map section missing"));
	if (find_player_spawn(w) == -1)
		return (-1);
	return (validate_map(w));
}

/* --------------------------- INIT PARSE LINES --------------------------- */

static void	init_parse_state(t_parse_state *s)
{
	s->map_started = 0;
	s->map_finished = 0;
	s->map_lines = 0;
	s->max_width = 0;
}

/* --------------------------- PROCESS ONE LINE --------------------------- */

static int	process_one_line(char *line, t_world *w, t_parse_state *s)
{
	size_t	len;
	int		status;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	status = parse_line(line, w, s);
	free(line);
	return (status);
}

/* --------------------------- MAIN LOOP --------------------------- */
static int	parse_lines(int fd, t_world *w)
{
	t_parse_state	s;
	char			*line;
	int				error;
	int				status;

	init_parse_state(&s);
	error = 0;
	line = read_line(fd, &error);
	while (line)
	{
		status = process_one_line(line, w, &s);
		if (status == -1)
			return (-1);
		line = read_line(fd, &error);
	}
	if (error)
		return (print_error("Failed to read .cub file"));
	return (finalize_parse(w, &s));
}

/* --------------------------- ENTRY POINT --------------------------- */

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
