#include "cub3d.h"

int	hardcode_world(t_world *w)
{
	// Exemple de petite map fermée
	static char *map_data[] = {
		"111111",
		"100001",
		"100001",
		"100001",
		"111111",
		NULL
	};

	w->map = map_data;
	w->map_w = 6;
	w->map_h = 5;

	// Couleurs sol / plafond (bleu ciel et gris foncé)
	w->ceiling_color = 0x87CEEB;  // bleu clair
	w->floor_color = 0x444444;    // gris foncé

	// Spawn du joueur
	w->spawn.pos.x = 5.0;
	w->spawn.pos.y = 2.5;
	w->spawn.dir.x = -1.0;
	w->spawn.dir.y = -0.0;
	w->spawn.plane.x = 0.0;
	w->spawn.plane.y = 0.66;

	// Textures (pour l’instant NULL — tu les chargerais plus tard)
	w->tx.no = NULL;
	w->tx.so = NULL;
	w->tx.we = NULL;
	w->tx.ea = NULL;
	w->tx.w = 64;
	w->tx.h = 64;

	return (0);
}
