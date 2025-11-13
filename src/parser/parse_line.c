/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:09:46 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/12 14:55:33 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char *skip_spaces(char *str)
{
    while (*str == ' ')
        str++;
    return (str);
}

static int  is_map_line(char *str)
{
    str = skip_spaces(str);
    if (*str == '\0')
        return (0);
    while (*str)
    {
        if (!ft_strchr("01NSEW \t", *str))
            return (0);
        str++;
    }
    return (1);
}

static char *dup_trimmed(const char *str)
{
    size_t  start;
    size_t  end;
    size_t  i;
    char    *copy;

    start = 0;
    while (str[start] == ' ')
        start++;
    end = ft_strlen((char *)str);
    while (end > start && str[end - 1] == ' ')
        end--;
    copy = (char *)malloc(sizeof(char) * (end - start + 1));
    if (!copy)
        return (NULL);
    i = 0;
    while (start + i < end)
    {
        copy[i] = str[start + i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

static int  set_texture(char *line, char **target)
{
    char    *trimmed;

    if (*target)
        return (print_error("Texture defined multiple times"));
    trimmed = dup_trimmed(line);
    if (!trimmed)
        return (print_error("Memory allocation failed"));
    if (*trimmed == '\0')
    {
        free(trimmed);
        return (print_error("Texture path missing"));
    }
    *target = trimmed;
    return (0);
}

static int	parse_config_line(char *line, t_world *w)
{
	char	*trim;

	trim = skip_spaces(line);
	if (!ft_strncmp(trim, "NO", 2) && trim[2] == ' ')
		return (set_texture(trim + 3, &w->paths.no));
	if (!ft_strncmp(trim, "SO", 2) && trim[2] == ' ')
		return (set_texture(trim + 3, &w->paths.so));
	if (!ft_strncmp(trim, "WE", 2) && trim[2] == ' ')
		return (set_texture(trim + 3, &w->paths.we));
	if (!ft_strncmp(trim, "EA", 2) && trim[2] == ' ')
		return (set_texture(trim + 3, &w->paths.ea));
	if (!ft_strncmp(trim, "F", 1) && trim[1] == ' ')
	{
		if (w->floor_color != -1)
			return (print_error("Floor color defined multiple times"));
		return (parse_rgb(trim + 2, &w->floor_color));
	}
	if (!ft_strncmp(trim, "C", 1) && trim[1] == ' ')
	{
		if (w->ceiling_color != -1)
			return (print_error("Ceiling color defined multiple times"));
		return (parse_rgb(trim + 2, &w->ceiling_color));
	}
	return (print_error("Invalid configuration line"));
}


int parse_line(char *line, t_world *w, t_parse_state *state)
{
    char    *trim;

    trim = line;
    while (*trim == ' ')
        trim++;
    if (*trim == '\0')
    {
        if (state->map_started)
            state->map_finished = 1;
        return (0);
    }
    if (state->map_finished && is_map_line(trim))
        return (print_error("Map interrupted by empty line"));
    if (is_map_line(trim))
        return (parse_map_line(line, w, state));
    if (state->map_started)
        return (print_error("Invalid data after map"));
    return (parse_config_line(trim, w));
}
