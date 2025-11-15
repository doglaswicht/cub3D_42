
#ifndef DEBUG_CUB3D
# define DEBUG_CUB3D 1  // 1 pour activer avec 0 désactivé
#endif

#include "cub3d.h"
struct s_column;
struct s_world;
struct s_player;
typedef struct s_raycast t_raycast;

void debug_dump_column_table(const t_column cols[5], const int idx[5]);

void debug_dump_raycast_table(const t_raycast rc[5], const int idx[5]);

void    debug_dump_state(const struct s_world *w, const struct s_player *p,
            const char *map_path);
void debug_dump_column(const struct s_column *col, int x);

void debug_dump_raycast(const t_raycast *rc, int x);



