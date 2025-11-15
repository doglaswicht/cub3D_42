#include "cub3d.h"
#include <stdio.h>
#include <math.h>

void debug_dump_raycast(const t_raycast *rc, int x)
{
    (void)rc;
    (void)x;
    printf("---- DEBUG RAYCAST x=%d ----\n", x);
    printf("raydir.x      = %f\n", rc->raydir.x);
    printf("raydir.y      = %f\n", rc->raydir.y);
    printf("map.x         = %f\n", rc->map.x);
    printf("map.y         = %f\n", rc->map.y);
    printf("side_dist.x   = %f\n", rc->side_dist.x);
    printf("side_dist.y   = %f\n", rc->side_dist.y);
    printf("delta_dist.x  = %f\n", rc->delta_dist.x);
    printf("delta_dist.y  = %f\n", rc->delta_dist.y);
    printf("perp_wall_dist= %f\n", rc->perp_wall_dist);
    printf("step_x        = %d\n", rc->step_x);
    printf("step_y        = %d\n", rc->step_y);
    printf("hit           = %d\n", rc->hit);
    printf("side          = %d\n", rc->side);
    printf("line_height   = %d\n", rc->line_height);
    printf("draw_start    = %d\n", rc->draw_start);
    printf("draw_end      = %d\n", rc->draw_end);
    printf("-----------------------------\n");
}

void debug_dump_raycast_table(const t_raycast rc[5], const int idx[5])
{
    char label[5][13];
    for (int i = 0; i < 5; i++)
        snprintf(label[i], 13, "x=%d", idx[i]);
    printf("==== TABLEAU DEBUG RAYCAST ====\n");
    printf("| Propriété        |");
    for (int i = 0; i < 5; i++)
        printf(" %11s|", label[i]);
    printf("\n");
    printf("|------------------|------------|------------|------------|------------|------------|\n");
    void print_float(double v) {
        if (v < 0)
            printf("%12.3f", v);
        else if (fabs(v) < 1e6)
            printf(" %11.3f", v);
        else
            printf(" %11.2e", v);
    }
    void print_int(int v) {
        if (v < 0)
            printf("%12d", v);
        else
            printf(" %11d", v);
    }
    printf("| raydir.x         | "); for(int i=0;i<5;i++){print_float(rc[i].raydir.x); printf(" |");} printf("\n");
    printf("| raydir.y         | "); for(int i=0;i<5;i++){print_float(rc[i].raydir.y); printf(" |");} printf("\n");
    printf("| map.x            | "); for(int i=0;i<5;i++){print_float(rc[i].map.x); printf(" |");} printf("\n");
    printf("| map.y            | "); for(int i=0;i<5;i++){print_float(rc[i].map.y); printf(" |");} printf("\n");
    printf("| side_dist.x      | "); for(int i=0;i<5;i++){print_float(rc[i].side_dist.x); printf(" |");} printf("\n");
    printf("| side_dist.y      | "); for(int i=0;i<5;i++){print_float(rc[i].side_dist.y); printf(" |");} printf("\n");
    printf("| delta_dist.x     | "); for(int i=0;i<5;i++){print_float(rc[i].delta_dist.x); printf(" |");} printf("\n");
    printf("| delta_dist.y     | "); for(int i=0;i<5;i++){print_float(rc[i].delta_dist.y); printf(" |");} printf("\n");
    printf("| perp_wall_dist   | "); for(int i=0;i<5;i++){print_float(rc[i].perp_wall_dist); printf(" |");} printf("\n");
    printf("| step_x           | "); for(int i=0;i<5;i++){print_int(rc[i].step_x); printf(" |");} printf("\n");
    printf("| step_y           | "); for(int i=0;i<5;i++){print_int(rc[i].step_y); printf(" |");} printf("\n");
    printf("| hit              | "); for(int i=0;i<5;i++){print_int(rc[i].hit); printf(" |");} printf("\n");
    printf("| side             | "); for(int i=0;i<5;i++){print_int(rc[i].side); printf(" |");} printf("\n");
    printf("| line_height      | "); for(int i=0;i<5;i++){print_int(rc[i].line_height); printf(" |");} printf("\n");
    printf("| draw_start       | "); for(int i=0;i<5;i++){print_int(rc[i].draw_start); printf(" |");} printf("\n");
    printf("| draw_end         | "); for(int i=0;i<5;i++){print_int(rc[i].draw_end); printf(" |");} printf("\n");
    printf("====================================================\n\n");
}