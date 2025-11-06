/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:31:36 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/06 17:03:53 by csturny          ###   ########.fr       */
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
#include "libft.h"         // pour ft_strlen


# define WIN_W  800
# define WIN_H  600

typedef struct s_image  // idem a image dans Yannik 
{
	void	*img;       // handle MLX vers l'image
	char	*addr;      // adresse mémoire du buffer de pixels
	int		bpp;        // bits par pixel
	int		line_len;   // nb d’octets par ligne
	int		endian;     // ordre des octets
}			t_image;


typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

/**
 * @struct s_player
 * @brief Représente l’état du joueur.
 * @var pos   Position du joueur dans la map (en cases)
 * @var dir   Direction dans laquelle il regarde (vecteur normalisé)
 * @var plane Vecteur du plan caméra (définit le FOV)
 */
typedef struct s_player
{
	t_vector	pos;    // Position du joueur dans la map
	t_vector	dir;    // Direction du regard
	t_vector	plane;  // Plan caméra (perpendiculaire à dir)
}	t_player;

/* remplcé par en haut s_player 
typedef struct s_player
{
    double  x;
    double  y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
    
}   t_player;*/

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
    char     **map;  // '0','1'
    int     map_w; // ajouté
    int     map_h; // ajouté 
    int     floor_color;
    int     ceiling_color;
    
}   t_world;

typedef struct  s_game
{
    void    *mlx;
    void    *win;
    t_image	frame;     // image tampon où tu dessines la frame
    t_world world;
    t_player player;         // état courant (copie initialisée depuis spawn)
} t_game;


/* mlx_init.c */
int		init_mlx(t_game *g);
int		init_images(t_game *g);

/* render.c */
void	render_frame(t_game *g);
void	clear_frame(t_game *g, int color);


void	player_init(t_game *g);
int	close_window(t_game *g);
void game_destroy(t_game *g);
int print_usage(void);
int game_init(t_game *g, const char *map_path);
void game_run(t_game *g);
void	print_map(t_world *w);

/*parsing (fonction qui seront faites par Doglas)*/

int load_map_simple(t_world *w, const char *path);
void	free_map(char **map, int h);



/* foncion pour doglas*/
//int parse_config(const char *path, t_world *out);


    /*
    // pour le parsing
    int     pase_config(consta char *path, t_world *out);   // parse_config() ne touche pas à MLX.
    // pour le rendu
    void    render_frame(t_game *g); // render_frame() ne lit jamais le fichier, ne loggue pas d’erreurs utilisateurs, et ne gère pas le clavier. Il prend l’état et dessine point.
    // pour les inputs
    void    handler_input(t_game *g);
    */

    /* fonction non utilisé
    void    my_mlx_pixel_put(t_img *img, int x, int y, int color);
    
    */
#endif
