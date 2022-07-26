#ifndef SRC_PRINT_H_
#define SRC_PRINT_H_
#include "objects.h"

#define X_MAX 100
#define Y_MAX 100

int **form_scene(wolf wolf, int *error);
void print_scene(int **scene);
void clean_arrs(int **arr, int size);

#endif  // SRC_PRINT_H
