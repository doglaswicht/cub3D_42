/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:11:49 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/12 14:22:47 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char map_at(t_world *w, int x, int y)
{
    size_t  len;

    if (y < 0 || y >= w->map_h || !w->map[y])
        return (' ');
    len = ft_strlen(w->map[y]);
    if (x < 0 || (size_t)x >= len)
        return (' ');
    return (w->map[y][x]);
}

static int  is_open_tile(t_world *w, int x, int y)
{
    if (x <= 0 || y <= 0 || x >= w->map_w - 1 || y >= w->map_h - 1)
        return (1);
    if (map_at(w, x - 1, y) == ' ' || map_at(w, x + 1, y) == ' ')
        return (1);
    if (map_at(w, x, y - 1) == ' ' || map_at(w, x, y + 1) == ' ')
        return (1);
    return (0);
}

int validate_map(t_world *w)
{
    int y;
    int x;
    char    tile;

    if (!w || !w->map)
        return (print_error("Map not initialized"));
    y = 0;
    while (y < w->map_h)
    {
        x = 0;
        while (x < w->map_w)
        {
            tile = map_at(w, x, y);
            if (tile == '\0')
                tile = ' ';
            if (!ft_strchr("01 NSEW", tile))
                return (print_error("Invalid character in map"));
            if (tile == '0' && is_open_tile(w, x, y))
                return (print_error("Map not closed"));
            x++;
        }
        y++;
    }
    return (0);
}