/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:39:57 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/18 16:12:32 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    rotate_player(t_game *g, double angle)
{
    double old_dir_x = g->player.dir.x;
    double old_plane_x = g->player.plane.x;
    q
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
