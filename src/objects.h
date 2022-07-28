#ifndef SRC_OBJECT_H_
#define SRC_OBJECT_H_

#define X_WOLF 14
#define Y_WOLF 5

typedef struct wolf {
    int **matrix;
} wolf;

typedef struct object {
    int **matrix;
} object;

wolf *import_wolf(char* path, int* error);

#endif  // SRC_OBJECT_H_
