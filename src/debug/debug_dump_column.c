
#include "cub3d.h"
#include <stdio.h>
#include <math.h>

void debug_dump_column_table(const t_column col[5], const int idx[5])
{
    char label[5][13];
    for (int i = 0; i < 5; i++)
        snprintf(label[i], 13, "x=%d", idx[i]);
    printf("==== TABLEAU DEBUG COLUMN ====\n");
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
    printf("| perp_dist        | "); for(int i=0;i<5;i++){print_float(col[i].perp_dist); printf(" |");} printf("\n");
    printf("| line_height      | "); for(int i=0;i<5;i++){print_int(col[i].line_height); printf(" |");} printf("\n");
    printf("| draw_start       | "); for(int i=0;i<5;i++){print_int(col[i].draw_start); printf(" |");} printf("\n");
    printf("| draw_end         | "); for(int i=0;i<5;i++){print_int(col[i].draw_end); printf(" |");} printf("\n");
    printf("| side             | "); for(int i=0;i<5;i++){print_int(col[i].side); printf(" |");} printf("\n");
    printf("| face             | "); for(int i=0;i<5;i++){print_int(col[i].face); printf(" |");} printf("\n");
    printf("| wall_x           | "); for(int i=0;i<5;i++){print_float(col[i].wall_x); printf(" |");} printf("\n");
    printf("| tex_x            | "); for(int i=0;i<5;i++){print_int(col[i].tex_x); printf(" |");} printf("\n");
    printf("====================================================\n\n");
}

void debug_dump_column(const t_column *col, int x)
{
    (void)col;
    (void)x;
#if DEBUG_CUB3D
    static int done = 0;
    if (done) return;
    done = 1;
    printf("---- DEBUG COLUMN x=%d ----\n", x);
    printf("perp_dist   = %f\n", col->perp_dist);
    printf("line_height = %d\n", col->line_height);
    printf("draw_start  = %d\n", col->draw_start);
    printf("draw_end    = %d\n", col->draw_end);
    printf("side        = %d\n", col->side);
    printf("face        = %d\n", col->face);
    printf("wall_x      = %f\n", col->wall_x);
    printf("tex_x       = %d\n", col->tex_x);
    printf("--------------------------\n");
#endif
}