/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:00:16 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/12 14:14:41 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct s_world t_world;
typedef struct s_game t_game;

typedef struct s_parse_state
{
    int map_started;
    int map_finished;
    int map_lines;
    int max_width;
}   t_parse_state;

int     parse_cub(char *path, t_game *game);
int     parse_line(char *line, t_world *w, t_parse_state *state);
int     parse_map_line(char *line, t_world *w, t_parse_state *state);
int     parse_rgb(const char *str, int *out_color);
int     validate_map(t_world *w);
int     find_player_spawn(t_world *w);


#endif
