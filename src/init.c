#include "init.h"

#include <ncurses.h>
#include <panel.h>
#include <unistd.h>

#include "print.h"

void init() {
    char c = 0;
    int stop = 1;
    int error = 0, kadr = 0, reverse = 0, move = 0;
    char *path = "sprites/wolf_2_1.txt";
    initscr();
    curs_set(0);
    nodelay(stdscr, TRUE);
    wolf *pwolf = NULL;
    while ((c = getch()) != EOF || stop != 0) {
        usleep(50000);
        clear();
        refresh();
        if (error == 0) {
            stop = get_key(c, &reverse, &move);
            pwolf = import_wolf(path, &error);
            int **scene = form_scene(*pwolf, &error, kadr, reverse, move);
            if (error == 0) {
                print_scene(scene);
                clean_arrs(scene, Y_MAX);
            }
            clean_arrs((*pwolf).matrix, Y_WOLF);
        }
        if (kadr == 0)
            kadr++;
        else
            kadr--;
    }
    endwin();
}

int get_key(char ch, int *reverse, int *move) {
    switch (ch) {
        case 'q':
            return 0;
        case 'a':
            if (*reverse == 0) {
                *reverse = 1;
            } else {
                if (*move > 0)
                    (*move)--;
            }
            break;
        case 'd':
            if (*reverse == 1) {
                *reverse = 0;
            } else {
                if (*move < X_MAX - X_WOLF - 1)
                    (*move)++;
            }
            break;
    }
    return 1;
}
