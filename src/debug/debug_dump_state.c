#ifndef DEBUG_CUB3D
# define DEBUG_CUB3D 1
#endif
#include <math.h>
#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif
#include "cub3d.h"

#if DEBUG_CUB3D

static void debug_print_color(const char *label, int color)
{
    int r;
    int g;
    int b;

    r = (color >> 16) & 0xFF;
    g = (color >> 8) & 0xFF;
    b = color & 0xFF;
    printf("  %s: 0x%06X  (r=%3d, g=%3d, b=%3d)\n",
        label, color, r, g, b);
}

static void debug_print_vector(const char *name, const t_vector *v)
{
    printf("  %s: (%.4f, %.4f)\n", name, v->x, v->y);
}

static void debug_print_player(const t_player *p)
{
    printf("[Player]\n");
    debug_print_vector("pos", &p->pos);
    debug_print_vector("dir", &p->dir);
    debug_print_vector("plane", &p->plane);
    double angle = atan2(p->dir.y, p->dir.x) * 180.0 / M_PI;
    printf("  angle: %.2f deg\n", angle);
    // Affichage direction cardinal
    char dir_char = '?';
    if (fabs(p->dir.x) > fabs(p->dir.y)) {
        if (p->dir.x > 0.7) dir_char = 'E';
        else if (p->dir.x < -0.7) dir_char = 'W';
    } else {
        if (p->dir.y > 0.7) dir_char = 'S';
        else if (p->dir.y < -0.7) dir_char = 'N';
    }
    printf("  start dir: %c\n", dir_char);
}

static void debug_print_textures(const t_textures *tx, const t_world *w)
{
    printf("[Textures]\n");
    printf("  north: img=%p  path=%s  size=%dx%d\n", tx->no.img, w->paths.no, tx->no.w, tx->no.h);
    printf("  south: img=%p  path=%s  size=%dx%d\n", tx->so.img, w->paths.so, tx->so.w, tx->so.h);
    printf("  east : img=%p  path=%s  size=%dx%d\n", tx->ea.img, w->paths.ea, tx->ea.w, tx->ea.h);
    printf("  west : img=%p  path=%s  size=%dx%d\n", tx->we.img, w->paths.we, tx->we.w, tx->we.h);
    printf("  (sizes sont dans t_image si tu les as remplis)\n");
}


static void debug_print_map_info(const t_world *w)
{
    int y;
    int count_0 = 0, count_1 = 0;

    printf("[Map]\n");
    printf("  size: %d x %d\n", w->map_w, w->map_h);
    if (!w->map)
    {
        printf("  map: (NULL)\n");
        return ;
    }
    y = 0;
    int px = (int)(w->spawn.pos.x);
    int py = (int)(w->spawn.pos.y);
    char spawn_c = 'P';
    // Détermine la lettre de spawn selon la direction
    if (fabs(w->spawn.dir.x) > fabs(w->spawn.dir.y)) {
        if (w->spawn.dir.x > 0.7) spawn_c = 'E';
        else if (w->spawn.dir.x < -0.7) spawn_c = 'W';
    } else {
        if (w->spawn.dir.y > 0.7) spawn_c = 'S';
        else if (w->spawn.dir.y < -0.7) spawn_c = 'N';
    }
    while (y < w->map_h)
    {
        printf("  ");
        for (int x = 0; w->map[y][x]; x++) {
            char c = w->map[y][x];
            if (x == px && y == py) {
                printf("\033[31m%c\033[0m", spawn_c); // rouge pour le joueur
            } else if (c == '1') {
                printf("\033[34m%c\033[0m", c); // bleu pour les murs
                count_1++;
            } else if (c == '0') {
                printf("%c", c); // blanc par défaut
                count_0++;
            } else {
                printf("%c", c);
            }
        }
        printf("\n");
        y++;
    }
    printf("  nb cases sol: %d, nb cases mur: %d\n", count_0, count_1);
}

void    debug_dump_state(const t_world *w, const t_player *p,
            const char *map_path)
{
    double  fov;

    printf("=============== CUB3D DEBUG ===============\n");
    printf("Map file : %s\n", map_path ? map_path : "(none)");
    debug_print_map_info(w);
    printf("[Colors]\n");
    debug_print_color("ceiling", w->ceiling_color);
    debug_print_color("floor  ", w->floor_color);
    debug_print_player(p);
    debug_print_textures(&w->tx, w);
    double plane_len = sqrt(p->plane.x * p->plane.x + p->plane.y * p->plane.y);
    double dir_len   = sqrt(p->dir.x * p->dir.x + p->dir.y * p->dir.y);
    fov = 2.0 * atan2(plane_len, dir_len);
    printf("[Render]\n");
    printf("  WIN: %d x %d\n", WIN_W, WIN_H);
    printf("  approx FOV: %.2f deg\n", fov * 180.0 / M_PI);
    printf("===========================================\n");
}

#else

void    debug_dump_state(const t_world *w, const t_player *p,
            const char *map_path)
{
    (void)w;
    (void)p;
    (void)map_path;
}

#endif
