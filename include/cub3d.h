/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:39:54 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/07 14:21:27 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ----- System / external deps -- */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

/* ----- Window & input -- */
# define ENABLE_SHADING
# define WIN_W       800
# define WIN_H       600

/* ----- Window & input -- */
# define KEY_ESC     65307
# define KEY_W       119
# define KEY_A       97
# define KEY_S       115
# define KEY_D       100
# define KEY_LEFT    65361
# define KEY_RIGHT   65363
# define EV_KEYPRESS 2
# define EV_KEYPRELEASE 3
# define EV_DESTROY  17

/* ----- Player movement & rotation speeds ----- */
# define MOVE_SPEED	0.001
# define ROT_SPEED 	0.001

/* ----- Rendering helpers -- */
# define FACE_NORTH 0
# define FACE_SOUTH 1
# define FACE_EAST  2
# define FACE_WEST  3

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}				t_image;

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}				t_player;

typedef struct s_column
{
	double	perp_dist;
	int		line_height;
	int		draw_wall_y_star;
	int		draw_wall_y_end;
	int		side;
	int		face;
	double	wall_hit_fraction_x;
	int		tex_x_index;
}				t_column;

typedef struct s_tex_paths
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}				t_tex_paths;

typedef struct s_textures
{
	t_image	no;
	t_image	so;
	t_image	we;
	t_image	ea;
}				t_textures;

typedef struct s_world
{
	t_player	spawn;
	t_textures	tx;
	char		**map;
	int			map_w;
	int			map_h;
	int			floor_color;
	int			ceiling_color;
	t_tex_paths	paths;
}				t_world;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
	int	esc;
}				t_keys;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			need_redraw;
	t_image		frame;
	t_world		world;
	t_player	player;
	t_keys		keys;
}				t_game;

typedef struct s_raycast
{
	t_vector	raydir;
	t_vector	map;
	t_vector	side_dist;
	t_vector	delta_dist;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			wall_y_start;
	int			wall_y_end;
}				t_raycast;

typedef struct s_parse_state
{
	int	map_started;
	int	map_finished;
	int	map_lines;
	int	max_width;
}				t_parse_state;

typedef struct s_wall_vars
{
	int		wall_col_start;
	int		wall_col_end;
	int		tex_x_index;
	int		current_y_row;
	int		*pixels_buffer;
	int		pixels_per_row;
	double	tex_y_scaling;
	double	tex_y_position;
}	t_wall_vars;

typedef struct s_bg_vars
{
	int	row_index;
	int	*pixels_buffer;
	int	pixels_per_row;
	int	half_height;
}	t_bg_vars;

/* ----- Init / teardown -- */
int				init_mlx(t_game *g);
int				init_images(t_game *g);
int				init_player_from_spawn(t_game *game);
int				init_textures_from_paths(t_game *g);
int				load_one_xpm(t_game *g, t_image *dst, const char *path);
int				game_init(t_game *g, const char *map_path);
void			game_run(t_game *g);
void			game_destroy(t_game *g);
void			destroy_world(t_world *world);
void			free_map(char **map, int h);

/* ----- Rendering / raycasting --*/
const t_image	*get_tex_for_face(const t_textures *tx, int face);
void			render_frame(t_game *g);
void			render_background(t_game *g);
void			render_walls(t_game *g, const t_column cols[WIN_W]);
void			cast_rays(const t_game *g, t_column cols[WIN_W]);
void			compute_dda_params(const t_game *g, t_raycast *rc);
void			run_dda(const t_game *g, t_raycast *rc);
void			compute_perp_distance(const t_game *g, t_raycast *rc);
void			compute_wall_height(t_raycast *rc);
void			fill_column_basic(t_column *col, const t_raycast *rc);
void			comupte_and_fill_column_tex(const t_game *g,
					t_column *col, const t_raycast *rc);
int				get_face(const t_raycast *rc);
int				apply_shading(int color, int side);
int				get_texel(const t_image *tex, int tx, int ty);
double			compute_wall_hit_fraction(const t_game *g, const t_raycast *rc);
int				compute_wall_texture_x(const t_game *g,
					const t_raycast *rc, double wall_x, int face);

/* ----- Parsing --*/
int				parse_cub(char *path, t_game *game);
int				parse_line(char *line, t_world *w, t_parse_state *state);
int				parse_map_line(char *line, t_world *w, t_parse_state *state);
int				parse_rgb(const char *str, int *out_color);
int				validate_map(t_world *w);
int				find_player_spawn(t_world *w);
char			*read_line(int fd, int *error);

/* ----- Input & gameplay -- */
int				close_window(t_game *g);
void			print_world_debug(const t_world *w);
int				key_press(int key, t_game *g);
int				key_release(int key, t_game *g);
int				handle_input(t_game *g);
int				handle_move(t_game *g);
void			move_player(t_game *g, double dx, double dy);
void			rotate_player(t_game *g, double angle);
int				is_wall(const t_world *w, double x, double y);

/* ----- Utils -- */
int				print_error(char *msg);
int				print_usage(void);
char			*skip_spaces(char *str);


#endif