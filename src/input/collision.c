/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:40:31 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/15 20:56:12 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
    * verifier si la position (x, y) dans le monde est un mur '1'
    * Convertion des cordenadas reais do jogador para coordenadas interas do mapa
*/
int is_wall(const t_world *w, double x, double y)
{
    int mx = (int)x;
    int my = (int)y;


    
    /*Fora do map -> trate como parede para evitar segfault*/
if(mx < 0 || my < 0 || my >= w->map_h || mx >= (int)ft_strlen(w->map[my]))
    return (1);

return(w->map[my][mx] == '1');

}

