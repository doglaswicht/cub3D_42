/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:10:24 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/12 14:22:20 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char *dup_line(const char *src)
{
    size_t  len;
    char    *copy;
    size_t  i;

    len = ft_strlen((char *)src);
    copy = (char *)malloc(sizeof(char) * (len + 1));
    if (!copy)
        return (NULL);
    i = 0;
    while (i < len)
    {
        copy[i] = src[i];
        i++;
    }
    copy[len] = '\0';
    return (copy);
}

static int  append_map_line(t_world *w, char *trimmed, t_parse_state *state)
{
    char    **new_map;
    int     i;

    new_map = (char **)malloc(sizeof(char *) * (state->map_lines + 2));
    if (!new_map)
        return (print_error("Memory allocation failed"));
    i = 0;
    while (i < state->map_lines)
    {
        new_map[i] = w->map[i];
        i++;
    }
    new_map[state->map_lines] = trimmed;
    new_map[state->map_lines + 1] = NULL;
    free(w->map);
    w->map = new_map;
    state->map_lines++;
    if ((int)ft_strlen(trimmed) > state->max_width)
        state->max_width = (int)ft_strlen(trimmed);
    w->map_h = state->map_lines;
    if (state->max_width > w->map_w)
        w->map_w = state->max_width;
    return (0);
}

int parse_map_line(char *line, t_world *w, t_parse_state *state)
{
    char    *dup;

    if (!line)
        return (print_error("Invalid map line"));
    dup = dup_line(line);
    if (!dup)
        return (print_error("Memory allocation failed"));
    if (append_map_line(w, dup, state) == -1)
    {
        free(dup);
        return (-1);
    }
    state->map_started = 1;
    return (0);
}