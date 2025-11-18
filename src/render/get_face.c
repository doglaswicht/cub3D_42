/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_face.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:39:31 by csturny           #+#    #+#             */
/*   Updated: 2025/11/16 13:40:25 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Determines which wall face (N, S, E, W) was hit by the ray.
 * @param rc Pointer to the raycasting result structure.
 * @return One of FACE_NORTH, FACE_SOUTH, FACE_EAST, or FACE_WEST.
 *
 * Uses the ray direction and the side hit (vertical/horizontal)
 * to identify the wall face.
 */
int	get_face(const t_raycast *rc)
{
	if (rc->side == 0)
	{
		if (rc->raydir.x > 0)
			return (FACE_EAST);
		else
			return (FACE_WEST);
	}
	else
	{
		if (rc->raydir.y > 0)
			return (FACE_SOUTH);
		else
			return (FACE_NORTH);
	}
}
