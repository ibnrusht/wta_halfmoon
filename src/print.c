#include "print.h"

#include <ncurses.h>
#include <stdlib.h>

#include "objects.h"

int **form_scene(wolf wolf, int *error, int kadr) {
    int **matrix = calloc(Y_MAX, sizeof(int *));
    int stars1[3][3] = {{32, 124, 32}, {45, '*', 45}, {32, 124, 32}};
    int stars2[3][3] = {{32, 32, 32}, {32, '*', 32}, {32, 32, 32}};
    if (matrix) {
        for (int i = 0; i < Y_MAX; i++) {
            matrix[i] = calloc(X_MAX, sizeof(int));
            if (matrix[i] == 0) {
                *error = 1;
                break;
            }
        }
        if (*error == 0) {
            wolf.matrix[0][0] = 0;
            insert_wolf(wolf, matrix);
            if (kadr == 1) {
                insert_stars(stars1, matrix);
            } else {
                insert_stars(stars2, matrix);
            }
        }
    }
    return matrix;
}

void insert_stars(int stars[3][3], int **matrix) {
    for (int i = 3; i < 6; i++)
        for (int j = 10; j < 13; j++) {
            matrix[i][j] = stars[i - 3][j - 10];
        }
}

void insert_wolf(wolf wolf, int **matrix) {
    for (int i = Y_MAX - Y_WOLF; i < Y_MAX; i++)
        for (int j = 0; j < X_WOLF; j++) {
            matrix[i][j] = wolf.matrix[i - Y_MAX + Y_WOLF][j];
        }
}

void print_scene(int **scene) {
    for (int i = 0; i < Y_MAX; i++)
        for (int j = 0; j < X_MAX; j++) {
            if (j != X_MAX - 1) {
                if (scene[i][j] == 0) {
                    printw(" ");
                } else {
                    printw("%c", scene[i][j]);
                }
            } else {
                if (scene[i][j] == 0) {
                    printw(" \n");
                } else {
                    printw("%c\n", scene[i][j]);
                }
            }
        }
}

void clean_arrs(int **arr, int size) {
    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);
}
