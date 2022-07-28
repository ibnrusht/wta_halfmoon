#ifndef SRC_PRINT_H_
#define SRC_PRINT_H_
#include "objects.h"

#define X_MAX 100
#define Y_MAX 40

void insert_stars(int stars[3][3], int **matrix);
void insert_wolf(wolf wolf, int **matrix, int inverse);
void wolf_tail_movement(wolf *wolf, int kadr);
int **form_scene(wolf wolf, int *error, int kadr, int inverse);
void print_scene(int **scene);
void clean_arrs(int **arr, int size);

#endif  // SRC_PRINT_H
