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
#include "init.h"

#include <ncurses.h>
#include <panel.h>
#include <unistd.h>

#include "print.h"

void init() {
    char c = 0;
    int stop = 1;
    int error = 0, count = 0, reverse = 0, position = 0;
    int move = 0;
    int tail_state = 0, star_state = 0;
    char *path = "../sprites/wolf_2_1.txt";
    initscr();
    curs_set(0);
    nodelay(stdscr, TRUE);
    wolf *pwolf = NULL;
    while ((c = getch()) != EOF || stop != 0) {
        erase();
        // usleep(500);
        if (error == 0) {
            stop = get_key(c, &reverse, &position, &move);
            state_change(&tail_state, &star_state, &move, &count);
            pwolf = import_wolf(path, &error);
            int **scene = form_scene(*pwolf, &error, tail_state,
                                     star_state, reverse, position, move);
            if (error == 0) {
                print_scene(scene);
                clean_arrs(scene, Y_MAX);
            }
            clean_arrs((*pwolf).matrix, Y_WOLF);
        }
    }
    endwin();
}

int get_key(char ch, int *reverse, int *position, int *move) {
    switch (ch) {
        case 'q':
            return 0;
        case 'a':
            if (*reverse == 0) {
                *reverse = 1;
                *move = 1;
            } else {
                if (*position > 0) {
                    (*position)--;
                    *move = 1;
                }
            }
            break;
        case 'd':
            if (*reverse == 1) {
                *reverse = 0;
                *move = 1;
            } else {
                if (*position < X_MAX - X_WOLF - 1) {
                    (*position)++;
                    *move = 1;
                }
            }
            break;
    }
    return 1;
}

void state_change(int *tail_state, int *star_state, int *move, int *count) {
    if (*count % 500 == 0)
        *tail_state = (*tail_state) ? 0 : 1;
    if (*count % 100 == 0)
        *star_state = (*star_state) ? 0 : 1;
    if (*count % 1000 == 0 && *move == 1)
        *move = 0;
    if (*count == 1000)
        (*count) = 0;
    (*count)++;
}
