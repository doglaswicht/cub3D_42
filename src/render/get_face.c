#include "cub3d.h"

int	get_face(const t_raycast *rc)
{
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
			return (FACE_SOUTH);
		else
			return (FACE_NORTH);
	}
}