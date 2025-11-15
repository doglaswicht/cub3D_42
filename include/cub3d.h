

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "mlx.h"
#include "parse.h"
#include "render.h"
#include "utils.h"
#include "libft.h"
#include "keys.h"

#define WIN_W  1920
#define WIN_H  1080

typedef struct s_image {
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    int     w;
    int     h;
} t_image;

typedef struct s_vector {
    double  x;
    double  y;
} t_vector;

typedef struct s_player {
    t_vector pos;
    t_vector dir;
    t_vector plane;
} t_player;

typedef struct s_column {
    double  perp_dist;
    int     line_height;
    int     draw_start;
    int     draw_end;
    int     side;
    int     face;
    double  wall_x;
    int     tex_x;
} t_column;

typedef struct s_tex_paths {
    char *no;
    char *so;
    char *we;
    char *ea;
} t_tex_paths;

typedef struct s_textures {
    t_image no;
    t_image so;
    t_image we;
    t_image ea;
} t_textures;

typedef struct s_world {
    t_player    spawn;
    t_textures  tx;
    char      **map;
    int         map_w;
    int         map_h;
    int         floor_color;
    int         ceiling_color;
    t_tex_paths paths;
} t_world;

typedef struct s_game {
    void    *mlx;
    void    *win;
    t_image frame;
    t_world world;
    t_player player;
} t_game;

void destroy_world(t_world *world);

typedef struct s_raycast {
    t_vector raydir;
    t_vector map;
    t_vector side_dist;
    t_vector delta_dist;
    double   perp_wall_dist;
    int      step_x;
    int      step_y;
    int      hit;
    int      side;
    int      line_height;
    int      draw_start;
    int      draw_end;
} t_raycast;

void debug_dump_raycast_table(const t_raycast rc[5], const int idx[5]);

/* mlx_init.c */
int init_mlx(t_game *g);
int init_images(t_game *g);
int init_player_from_spawn(t_game *game);
int init_textures_from_paths(t_game *g);

/* textures */
int init_textures_hardcode(t_game *g);
int get_texel(const t_image *tex, int tx, int ty);
int load_one_xpm(t_game *g, t_image *dst, const char *path);
int get_tex_y(const t_image *tex, int line_height, int y, int start);
double compute_wall_x(const t_game *g, const t_raycast *rc);
int compute_tex_x(const t_game *g, const t_raycast *rc, double wall_x, int face);
int get_tex_y_from_start(const t_image *tex, int line_height, int y, int start);
const t_image *get_tex_for_face(const t_textures *tx, int face);

/* render.c */
void render_frame(t_game *g);
void clear_frame(t_game *g, int color);

int close_window(t_game *g);
void game_destroy(t_game *g);
int print_usage(void);
int game_init(t_game *g, const char *map_path);
void game_run(t_game *g);
void print_map(t_world *w);
void my_mlx_pixel_put(t_image *img, int x, int y, int color);

/* raycasting */
void render_background(t_game *g);
void draw_vertical_line(t_game *g, int x, int y_start, int y_end, int color);
void compute_dda_params(const t_game *g, t_raycast *rc);
void run_dda(const t_game *g, t_raycast *rc);
void compute_perp_distance(const t_game *g, t_raycast *rc);
void compute_wall_height(t_raycast *rc);
void cast_rays(const t_game *g, t_column cols[WIN_W], t_raycast rc_debug[5], int idx[5], int n);
void render_walls(t_game *g, const t_column cols[WIN_W]);
int get_face(const t_raycast *rc);
int hardcode_world(t_world *w);
void print_world_debug(const t_world *w);
void fill_column_basic(t_column *col, const t_raycast *rc);
void fill_column_tex(const t_game *g, t_column *col, const t_raycast *rc);

/* parsing */
void free_map(char **map, int h);

/* debug */
void debug_faces_once(const t_column cols[WIN_W]);

#endif
