#include "cub3d.h"

/**
 * @brief Determines which wall face (N, S, E, W) was hit by the ray.
 * @param rc Pointer to the raycasting result structure.
 * @return One of FACE_NORTH, FACE_SOUTH, FACE_EAST, or FACE_WEST.
 *
 * Uses the ray direction and the side hit (vertical/horizontal) to identify the wall face.
 */
int	get_face(const t_raycast *rc)
{
	//Pour corriger l’inversion Est/Ouest, il faut inverser ces deux retours :
	if (rc->side == 0)
	{
		if (rc->raydir.x > 0)
			return (FACE_WEST);
		else
			return (FACE_EAST);
	}
	else
	{
		// ICI : on inverse N/S par rapport à ce que tu avais
		if (rc->raydir.y > 0)
			return (FACE_NORTH);
		else
			return (FACE_SOUTH);
	}
}