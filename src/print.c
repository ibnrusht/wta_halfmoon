#include "print.h"

// #include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "objects.h"

int **form_scene(wolf wolf, int *error) {
    int **matrix = calloc(Y_MAX, sizeof(int *));
    if (matrix) {
        for (int i = 0; i < Y_MAX; i++) {
            matrix[i] = calloc(X_MAX, sizeof(int));
            if (matrix[i] == 0) {
                *error = 1;
                break;
            }
        }
        if (*error == 0) {
            for (int i = Y_MAX - Y_WOLF; i < Y_MAX; i++)
                for (int j = 0; j < X_WOLF; j++) {
                    matrix[i][j] = wolf.matrix[i - Y_MAX + Y_WOLF][j];
                }
        }
    }
    return matrix;
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
                if (scene[i][j] == 0)
                    printw(" \n");
                else
                    printw("%c\n", scene[i][j]);
            }
        }
}

void clean_arrs(int **arr, int size) {
    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);
}
