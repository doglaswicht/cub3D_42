#include "cub3d.h"

// provisoir

// provisoir pour charger une texture
/**
 * @brief Loads an XPM texture file into a t_image structure using MiniLibX.
 * @param g Pointer to the game state (provides MLX context).
 * @param dst Pointer to the destination t_image structure to fill.
 * @param path Path to the XPM texture file.
 * @return 0 on success, -1 on failure.
 *
 * Loads the image, retrieves its pixel buffer and metadata, and stores them in dst.
 */
int load_one_xpm(t_game *g, t_image *dst, const char *path)
{
    dst->img = mlx_xpm_file_to_image(g->mlx, (char *)path, &dst->w, &dst->h);
    if (!dst->img) return (-1);
    dst->addr = mlx_get_data_addr(dst->img, &dst->bpp, &dst->line_len, &dst->endian);
    return (dst->addr ? 0 : -1);
}


// provisoir pour focer une texture
// texture écrit en dure ici
/**
 * @brief Loads hardcoded wall textures for all four directions (N, S, E, W).
 * @param g Pointer to the game state.
 * @return 0 on success, -1 on failure.
 *
 * Loads each wall texture from a fixed path and prints its properties.
 * If any texture fails to load, returns -1 immediately.
 */
int init_textures_hardcode(t_game *g)
{
    if (load_one_xpm(g, &g->world.tx.no, "textures/Wall1.xpm") < 0) return (-1);
    printf("[TX] Wall1.xpm: %dx%d  bpp=%d  line=%d  endian=%d\n",
        g->world.tx.no.w, g->world.tx.no.h, g->world.tx.no.bpp, g->world.tx.no.line_len, g->world.tx.no.endian);

    if (load_one_xpm(g, &g->world.tx.so, "textures/Wall2.xpm") < 0) return (-1);
    printf("[TX] Wall2.xpm: %dx%d  bpp=%d  line=%d  endian=%d\n",
        g->world.tx.so.w, g->world.tx.so.h, g->world.tx.so.bpp, g->world.tx.so.line_len, g->world.tx.so.endian);

    if (load_one_xpm(g, &g->world.tx.ea, "textures/Wall4.xpm")  < 0) return (-1);
    printf("[TX] Wall3.xpm: %dx%d  bpp=%d  line=%d  endian=%d\n",
        g->world.tx.ea.w, g->world.tx.ea.h, g->world.tx.ea.bpp, g->world.tx.ea.line_len, g->world.tx.ea.endian);

    if (load_one_xpm(g, &g->world.tx.we, "textures/Wall3.xpm")  < 0) return (-1);
    printf("[TX] Wall4.xpm: %dx%d  bpp=%d  line=%d  endian=%d\n",
        g->world.tx.we.w, g->world.tx.we.h, g->world.tx.we.bpp, g->world.tx.we.line_len, g->world.tx.we.endian);

    return (0);
}