/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:39:45 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/15 21:05:25 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void   move_player(t_game *g, double dx, double dy)
{
    double new_x = g->player.pos.x + dx;
    double new_y = g->player.pos.y + dy;


/*testa colisoao no eixo X*/
if(!is_wall(&g->world, new_x, g->player.pos.y))
    g->player.pos.x  = new_x;

/*testa colisao no eixo y */
if(!is_wall(&g->world, g->player.pos.x, new_y))
    g->player.pos.y = new_y;
}