
#include "cub3d.h"

static int	move_forward(t_game *g)
{
    if (g->keys.w)
    {
        move_player(g, g->player.dir.x * MOVE_SPEED, g->player.dir.y * MOVE_SPEED);
        return (1);
    }
    return (0);
}

static int	move_backward(t_game *g)
{
    if (g->keys.s)
    {
        move_player(g, -g->player.dir.x * MOVE_SPEED, -g->player.dir.y * MOVE_SPEED);
        return (1);
    }
    return (0);
}

static int	move_left(t_game *g)
{
    if (g->keys.a)
    {
        move_player(g, -g->player.plane.x * MOVE_SPEED, -g->player.plane.y * MOVE_SPEED);
        return (1);
    }
    return (0);
}

static int	move_right(t_game *g)
{
    if (g->keys.d)
    {
        move_player(g, g->player.plane.x * MOVE_SPEED, g->player.plane.y * MOVE_SPEED);
        return (1);
    }
    return (0);
}

int	handle_move(t_game *g)
{
    int changed = 0;
    if (move_forward(g))
        changed = 1;
    if (move_backward(g))
        changed = 1;
    if (move_left(g))
        changed = 1;
    if (move_right(g))
        changed = 1;
    return (changed);
}