/*
 * Created Date: Friday July 29th 2022
 * Author: Amir Khadiev
 * email: <ibn.rusht@gmail.com>
 * -----
 * Last Modified: Thu Aug 04 2022
 * Modified By: Amir Khadiev
 * -----
 * Copyright 2022 Amir Khadiev
 */
#include "print.h"

#include <ncurses.h>
#include <stdlib.h>

#include "movements.h"

int **form_scene(wolf wolf, int *error, int tail_state, int star_state,
                 int inverse, int position, int move) {
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
            wolf_tail_movement(&wolf, tail_state);
            wolf_movement(&wolf, move);
            insert_stars(star_state, matrix);
            insert_wolf(wolf, matrix, inverse, position);
        }
    }
    return matrix;
}

void insert_stars(int star_state, int **matrix) {
    int stars1[3][3] = {{0, 0, 0}, {0, '+', 0}, {0, 0, 0}};
    int stars2[3][3] = {{0, '|', 0}, {'-', '+', '-'}, {0, '|', 0}};
    for (int m = 0; m < X_MAX; m += 10) {
        int m_i = (m % 4) ? 3 : 6;
        for (int i = m_i; i < 3 + m_i; i++)
            for (int j = m; j < m + 3; j++) {
                matrix[i][j] = (star_state) ? stars1[i - m_i][j - m]
                                            : stars2[i - m_i][j - m];
            }
    }
}

void insert_wolf(wolf wolf, int **matrix, int inverse, int position) {
    for (int i = Y_MAX - Y_WOLF; i < Y_MAX; i++)
        for (int j = 0; j < X_WOLF; j++) {
            matrix[i][position + j] =
                wolf.matrix[i - Y_MAX + Y_WOLF][(inverse) ? X_WOLF - j - 1 : j];
            if (inverse) {
                if (matrix[i][position + j] == '(')
                    matrix[i][position + j] = ')';
                else if (matrix[i][position + j] == ')')
                    matrix[i][position + j] = '(';
                else if (matrix[i][position + j] == '/')
                    matrix[i][position + j] = '\\';
                else if (matrix[i][position + j] == '\\')
                    matrix[i][position + j] = '/';
                else if (matrix[i][position + j] == '{')
                    matrix[i][position + j] = '}';
            }
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
