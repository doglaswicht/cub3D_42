/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:39:57 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/15 21:30:04 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    rotate_player(t_game *g, double angle)
{
    double old_dir_x = g->player.dir.x;
    double old_plane_x = g->player.dir.y;
    
    /* rotaciona vetor direcao*/
    g->player.dir.x  = g->player.dir.x * cos(angle)
        - g->player.dir.y * sin(angle);
    g->player.dir.y = old_dir_x * sin(angle)
        + g->player.dir.y * cos(angle);

    /*rotaciona plano da camera FOV */
    g->player.plane.x = g->player.plane.x * cos(angle)
        - g->player.plane.y * sin(angle);
    g->player.plane.y = old_plane_x * sin(angle)
        + g->player.plane.y * cos(angle);
}
