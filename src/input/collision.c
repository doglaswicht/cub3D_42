/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:40:31 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/16 09:37:37 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
    * verifier si la position (x, y) dans le monde est un mur '1'
    * Convertion des cordenadas reais do jogador para coordenadas interas do mapa
*/
// attention modification csturny // gère longuer de murs non constante
int is_wall(const t_world *w, double x, double y)
{
    int mx = (int)x;
    int my = (int)y;

    /* Hors map ou hors ligne = mur */
    if (mx < 0 || my < 0 || my >= w->map_h)
        return (1);
    int line_len = w->map[my] ? (int)ft_strlen(w->map[my]) : 0;
    if (mx >= line_len)
        return (1);
    return (w->map[my][mx] == '1');

}

