#include "cub3d.h"

// je n'utilise plus

/*
 * Initialise la position, la direction et le plan caméra du joueur.
 * Pour l’instant : position en dur au centre de la map,
 * direction vers l’Est, FOV ~ 66°.
 */
void	player_init(t_game *g)
{
	// 1) Position du joueur
	// Version simple : au centre de la map (approximativement).
	// Si ta map est :
	// 111111
	// 100001
	// 100001
	// 100001
	// 111111
	// alors map_w = 6, map_h = 5.
	// On met le joueur vers le centre intérieur.
	g->player.pos.x = g->world.map_w / 2.0;
	g->player.pos.y = g->world.map_h / 2.0;

	//g->player.pos.x = 1.0;
	//g->player.pos.y = 2.5;

	// Variante encore plus safe : tu peux choisir une case connue "0"
	// g->player.pos.x = 2.5;
	// g->player.pos.y = 2.5;

	// 2) Direction du regard
	// On le fait regarder vers l’Est (droite) :
	// nord bleu?
	g->player.dir.x = 0.70;
	g->player.dir.y = 0.70;

	// 3) Plan caméra
	// Le plan est perpendiculaire à dir.
	// Si dir = (1, 0), un plan perpendiculaire est (0, 1).
	// On le scale par ~0.66 pour donner un FOV ≈ 66° (classique raycasting).
	g->player.plane.x = 0.0;
	g->player.plane.y = 0.66;

    // Debug temporaire
	printf("[DEBUG] Player initialized:\n");
	printf("  pos   = (%f, %f)\n", g->player.pos.x, g->player.pos.y);
	printf("  dir   = (%f, %f)\n", g->player.dir.x, g->player.dir.y);
	printf("  plane = (%f, %f)\n", g->player.plane.x, g->player.plane.y);
}
