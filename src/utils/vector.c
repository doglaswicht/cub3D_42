/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:38:12 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/16 21:40:54 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Cumpriment du vector */

double	vec_len(t_vector v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

/*normalizer vector*/
t_vector	vec_norm(t_vector v)
{
	double len = vec_len(v);

	t_vector out;
	out.x = v.x / len;
	out.y = v.y / len;
	return out;
}
/* rotacioner vector par angle*/
t_vector	vec_rot(t_vector v, double a)
{
	t_vector r;

	r.x = v.x * cos(a) - v.y * sin(a);
	r.y = v.x * sin(a) + v.y * cos(a);
	return r;
}
