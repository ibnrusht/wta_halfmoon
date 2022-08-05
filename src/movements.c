/*
 * Created Date: Wednesday August 3rd 2022
 * Author: Amir Khadiev
 * email: <ibn.rusht@gmail.com>
 * -----
 * Last Modified: Fri Aug 05 2022
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

void y_position_change(int *position, int *v0) {
    if (*v0 >= 0) {
        position[1] = position[1] + *v0 + G;
    } else if (*v0 < 0 && position[1] > 0) {
        position[1] = position[1] - (-(*v0) + G);
    }
    if (position[1] < 0 || position[1] >= Y_MAX - Y_WOLF)
        position[1] = 0;
    *v0 -= G;
}

void wolf_jump(int *position, int count, int *jump_state) {
    static int v0 = 0;
    if (*jump_state == 1) {
        v0 = V0;
        y_position_change(position, &v0);
        *jump_state = 2;
    } else if (*jump_state == 2) {
        if (count % 500 == 0 && v0 >= -V0)
            y_position_change(position, &v0);
        else if (v0 < -V0) {
            v0 = 0;
            *jump_state = 0;
            position[1] = 0;
        }
    }
}
