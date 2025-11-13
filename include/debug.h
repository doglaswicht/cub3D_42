#ifndef DEBUG_CUB3D
# define DEBUG_CUB3D 1  // 1 pour activer avec 0 désactivé
#endif

struct s_world;
struct s_player;

void    debug_dump_state(const struct s_world *w, const struct s_player *p,
            const char *map_path);
