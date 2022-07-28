#ifndef SRC_PRINT_H_
#define SRC_PRINT_H_
#include "objects.h"

#define X_MAX 100
#define Y_MAX 30

void insert_stars(int star_state, int **matrix);
void insert_wolf(wolf wolf, int **matrix, int inverse, int move);
void wolf_tail_movement(wolf *wolf, int kadr);
void wolf_movement(wolf *wolf, int move);
int **form_scene(wolf wolf, int *error, int tail_state,
                 int star_state, int inverse, int position, int move);
void print_scene(int **scene);
void clean_arrs(int **arr, int size);

#endif  // SRC_PRINT_H
