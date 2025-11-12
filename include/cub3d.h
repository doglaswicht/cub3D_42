/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:31:36 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/12 12:05:01 by csturny          ###   ########.fr       */
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

// remarque ajouté w et h
typedef struct s_image  // idem a image dans Yannik 
{
	void	*img;       // handle MLX vers l'image
	char	*addr;      // adresse mémoire du buffer de pixels
	int		bpp;        // bits par pixel
	int		line_len;   // nb d’octets par ligne
	int		endian;     // ordre des octets
    int     w;      // largeur
    int     h;      // hauteur
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

typedef struct s_column
{
    double  perp_dist;
    int     line_height;
    int     draw_start;
    int     draw_end;
    int     side;      // 0 = vertical, 1 = horizontal
    int     face;      // 0=N,1=S,2=E,3=O (on verra après)
    double  wall_x;    // [0,1) coord sur le mur
    int     tex_x;     // coord X dans la texture
}   t_column;

/*
//old
typedef struct s_textures
{
    void *no;//nord
    void *so;//sud
    void *we;//ouest
    void *ea;//est
    int w;
    int h;
    
} t_textures;
*/

// new
// remarque enlevé w et h
typedef struct s_textures {
    t_image no;
    t_image so;
    t_image we;
    t_image ea;
} t_textures;

typedef struct s_world
{
    t_player    spawn; // joueur
    t_textures  tx;  // texture
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


/**
 * @struct s_raycast
 * @brief Contient toutes les informations nécessaires pour le calcul
 *        et l'affichage d'un seul rayon du raycasting.
 */
typedef struct s_raycast
{
	/* --- Direction du rayon --- */
    t_vector	raydir;        // direction du rayon
    /* --- Position actuelle du rayon dans la map --- */
	t_vector	map;           // case actuelle dans la map (x, y entiers)
    
    /* --- Distances utilisées pour le DDA --- */
	t_vector	side_dist;     // distance jusqu’à la prochaine ligne de grille
	t_vector	delta_dist;    // distance entre deux lignes successives
	double		perp_wall_dist; // distance perpendiculaire entre le joueur et le mur touché

	/* --- Direction d’avancement dans la map --- */
	int		step_x;          // sens de déplacement sur l’axe X (+1 ou -1)
	int		step_y;          // sens de déplacement sur l’axe Y (+1 ou -1)

	/* --- Informations de collision --- */
	int		hit;             // 0 = pas encore de mur, 1 = mur trouvé
	int		side;            // 0 = mur vertical, 1 = mur horizontal (utilisé pour ombrage)

	/* --- Projection du mur à l’écran --- */
	int		line_height;     // hauteur en pixels du mur à dessiner
	int		draw_start;      // pixel Y de début du mur à l’écran
	int		draw_end;        // pixel Y de fin du mur à l’écran
}	t_raycast;



/* mlx_init.c */
int		init_mlx(t_game *g);
int		init_images(t_game *g);

/*textures*/
int init_textures_hardcode(t_game *g);
int get_texel(const t_image *tex, int tx, int ty);
int load_one_xpm(t_game *g, t_image *dst, const char *path);
int get_tex_y(const t_image *tex, int line_height, int y, int start);
double compute_wall_x(const t_game *g, const t_raycast *rc);
int compute_tex_x(const t_game *g, const t_raycast *rc, double wall_x, int face);
int get_tex_y_from_start(const t_image *tex, int line_height, int y, int start);
const t_image *get_tex_for_face(const t_textures *tx, int face);

/* render.c */
void	render_frame(t_game *g);
void	clear_frame(t_game *g, int color);



int	close_window(t_game *g);
void game_destroy(t_game *g);
int print_usage(void);
int game_init(t_game *g, const char *map_path);
void game_run(t_game *g);
void	print_map(t_world *w);
void    my_mlx_pixel_put(t_image *img, int x, int y, int color);



/*raycasting*/


void	render_background(t_game *g);
void	draw_vertical_line(t_game *g, int x, int y_start, int y_end, int color); // provioir juste pour desinier une seule ligne vertival
void	compute_dda_params(const t_game *g, t_raycast *rc);
void	run_dda(const t_game *g, t_raycast *rc);
void    compute_perp_distance(const t_game *g, t_raycast *rc);
void    compute_wall_height(t_raycast *rc);
void    cast_rays(const t_game *g, t_column cols[WIN_W]);
void render_walls(t_game *g, const t_column cols[WIN_W]);
int	get_face(const t_raycast *rc);
int	hardcode_world(t_world *w);
void	print_world_debug(const t_world *w);
void fill_column_basic(t_column *col, const t_raycast *rc);
void fill_column_tex(const t_game *g, t_column *col, const t_raycast *rc);



/*parsing (fonction qui seront faites par Doglas)*/

//int load_map_simple(t_world *w, const char *path);
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
