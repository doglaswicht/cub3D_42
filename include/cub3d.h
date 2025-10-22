/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:31:36 by dleite-b          #+#    #+#             */
/*   Updated: 2025/10/22 14:08:49 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3d_H
# define CUB3d_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "mlx.h"
#include "parse.h"
#include "render.h"
#include "utils.h"

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}   t_img;


typedef struct s_player
{
    double  x;
    double  y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
    
}   t_player;

//
typedef struct s_textures
{
    void *no;//nord
    void *so;//sud
    void *we;//ouest
    void *ea;//est
    int w;
    int h;
    
} t_textures;

typedef struct s_world
{
    t_player    spawn;
    t_textures  tx;
    char     **maps;
    int     floor_color;
    int     ceiling_color;
    
}   t_world;

typedef struct  s_game
{
    void    *mlx;
    void    *win;
    t_world world;
    t_player p;
} t_game;

    int init_game(t_game *game, char *map_path);
    void    my_mlx_pixel_put(t_img *img, int x, int y, int color);

    /*
    int     pase_config(consta char *path, t_world *out);
    void    render_frame(t_game *g);
    void    handler_input(t_game *g);
    */
#endif
