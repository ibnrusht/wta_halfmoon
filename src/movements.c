/*
 * Created Date: Wednesday August 3rd 2022
 * Author: Amir Khadiev
 * email: <ibn.rusht@gmail.com>
 * -----
 * Last Modified: Thu Aug 04 2022
 * Modified By: Amir Khadiev
 * -----
 * Copyright 2022 Amir Khadiev
 */
#include "movements.h"

void wolf_tail_movement(wolf *wolf, int state) {
    int k = 0, l = 1, m = 2;
    if (state == 1) {
        (*wolf).matrix[0][l] = (*wolf).matrix[0][l] - 1;
        (*wolf).matrix[1][m] = ')';
        (*wolf).matrix[1][l] = (*wolf).matrix[1][m];
        (*wolf).matrix[1][k] = 0;
        (*wolf).matrix[2][m] = '(';
        (*wolf).matrix[2][l] = (*wolf).matrix[2][m];
        (*wolf).matrix[2][k] = 0;
    }
}

void wolf_movement(wolf *wolf, int move) {
    if (move == 1) {
        (*wolf).matrix[3][0] = '/';
        (*wolf).matrix[3][2] = '/';
        (*wolf).matrix[4][0] = '*';
        (*wolf).matrix[4][2] = '*';
        (*wolf).matrix[4][1] = 0;
        (*wolf).matrix[4][3] = 0;
        (*wolf).matrix[3][10] = ')';
        (*wolf).matrix[3][11] = ')';
        (*wolf).matrix[3][9] = 0;
        (*wolf).matrix[4][9] = '*';
        (*wolf).matrix[4][10] = '*';
        (*wolf).matrix[4][11] = 0;
    }
}

void wolf_jump(int *move_y, int v0) {
    static int v = 0;
    if (v0 == V0)
        v = v0;
    if (v > 0) {
        (*move_y) += v - G / 2;
        v -= G;
    } else if (v < 0) {
        (*move_y) -= v + G / 2;
        v += G;
    } else {
        v += G;
    }
}
