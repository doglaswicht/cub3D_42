#include "cub3d.h"


// porvisoir a remplacer par Doglas
int	hardcode_world(t_world *w)
{
	// Exemple de petite map fermée
	static char *map_data[] = {
    "1111111111",
    "1000000001",
    "1000000001",
    "1000000001",
    "1000000001",
    "1000000001",
    "1000000001",
    "1000000001",
    "1000000001",
    "1111111111",
    NULL
	};

	w->map = map_data;
	w->map_w = 10;
	w->map_h = 10;

	// Couleurs sol / plafond (bleu ciel et gris foncé)
	w->ceiling_color = 0x87CEEB;  // bleu clair
	w->floor_color = 0x444444;    // gris foncé

	// Spawn du joueur
	w->spawn.pos.x = 5.0;
	w->spawn.pos.y = 5.0;
	w->spawn.dir.x = 0.0;
	w->spawn.dir.y = 1.0;
	w->spawn.plane.x = -0.66;
	w->spawn.plane.y = 0.0;

	// Textures (pour l’instant NULL — tu les chargerais plus tard)
	w->tx.no.img = NULL;
	w->tx.so.img = NULL;
	w->tx.we.img = NULL;
	w->tx.ea.img = NULL;
	w->tx.no.w = 64;
	w->tx.no.h = 64;


	return (0);
}
