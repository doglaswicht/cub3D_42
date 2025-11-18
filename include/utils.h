/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:49:38 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/18 15:33:36 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>   // para uint32_t
# include <stdlib.h>   // para exit()
# include <math.h>     // para trigonometria
# include <unistd.h>   // para write()

typedef struct s_vector {
    double  x;
    double  y;
} t_vector;

/* ----------- FUNÇÕES MATEMÁTICAS ----------- */

double      vec_len(t_vector v);
t_vector    vec_norm(t_vector v);
t_vector    vec_rot(t_vector v, double a);



/* ---------------- ERROS ---------------- */

void        die(const char *msg);
int         error(const char *ctx, const char *detail);

/* ----------- OUTRAS UTILS (SEUS) ----------- */

int         clampi(int value, int min, int max);
int         print_error(char *msg);
void        free_map(char **map, int h);

#endif