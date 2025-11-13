#include "cub3d.h"

#if DEBUG_CUB3D

static void count_faces(const t_column cols[WIN_W],
    int *n, int *s, int *e, int *w)
{
    int i;

    *n = 0;
    *s = 0;
    *e = 0;
    *w = 0;
    i = 0;
    while (i < WIN_W)
    {
        if (cols[i].face == FACE_NORTH)
            (*n)++;
        else if (cols[i].face == FACE_SOUTH)
            (*s)++;
        else if (cols[i].face == FACE_EAST)
            (*e)++;
        else if (cols[i].face == FACE_WEST)
            (*w)++;
        i++;
    }
}

void    debug_faces_once(const t_column cols[WIN_W])
{
    static int  done = 0;
    int         n;
    int         s;
    int         e;
    int         w;

    if (done)
        return ;
    done = 1;
    count_faces(cols, &n, &s, &e, &w);
    printf("[DEBUG] Faces touchées sur 1 frame:\n");
    printf("  NORTH: %d colonnes\n", n);
    printf("  SOUTH: %d colonnes\n", s);
    printf("  EAST : %d colonnes\n", e);
    printf("  WEST : %d colonnes\n", w);
}

#else

void    debug_faces_once(const t_column cols[WIN_W])
{
    (void)cols;
}

#endif
