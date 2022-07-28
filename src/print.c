#include "print.h"

#include <ncurses.h>
#include <stdlib.h>

#include "objects.h"

int **form_scene(wolf wolf, int *error, int kadr, int inverse, int move) {
    int **matrix = calloc(Y_MAX, sizeof(int *));
    int stars1[3][3] = {{0, 0, 0}, {0, '+', 0}, {0, 0, 0}};
    int stars2[3][3] = {{0, '|', 0}, {'-', '+', '-'}, {0, '|', 0}};
    if (matrix) {
        for (int i = 0; i < Y_MAX; i++) {
            matrix[i] = calloc(X_MAX, sizeof(int));
            if (matrix[i] == 0) {
                *error = 1;
                break;
            }
        }
        if (*error == 0) {
            wolf_tail_movement(&wolf, kadr);
            insert_wolf(wolf, matrix, inverse, move);
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
    for (int m = 0; m < X_MAX; m += 10) {
        int m_i = (m % 4) ? 3 : 6;
        for (int i = m_i; i < 3 + m_i; i++)
            for (int j = m; j < m + 3; j++) {
                matrix[i][j] = stars[i - m_i][j - m];
            }
    }
}

void insert_wolf(wolf wolf, int **matrix, int inverse, int move) {
    for (int i = Y_MAX - Y_WOLF; i < Y_MAX; i++)
        for (int j = 0; j < X_WOLF; j++) {
            matrix[i][move + j] = wolf.matrix[i - Y_MAX + Y_WOLF][(inverse) ? X_WOLF - j - 1 : j];
            if (inverse) {
                if (matrix[i][j] == '(')
                    matrix[i][j] = ')';
                else if (matrix[i][j] == ')')
                    matrix[i][j] = '(';
                else if (matrix[i][j] == '/')
                    matrix[i][j] = '\\';
                else if (matrix[i][j] == '\\')
                    matrix[i][j] = '/';
                else if (matrix[i][j] == '{')
                    matrix[i][j] = '}';
            }
        }
}

void wolf_tail_movement(wolf *wolf, int kadr) {
    int k = 8, l = 9, m = 10;
    if (kadr == 1) {
        (*wolf).matrix[0][l] = (*wolf).matrix[0][l] - 1;
        (*wolf).matrix[1][m] = ')';
        (*wolf).matrix[1][l] = (*wolf).matrix[1][m];
        (*wolf).matrix[1][k] = 0;
        (*wolf).matrix[2][m] = '(';
        (*wolf).matrix[2][l] = (*wolf).matrix[2][m];
        (*wolf).matrix[2][k] = 0;
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
