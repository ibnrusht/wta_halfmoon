#include "init.h"

#include <ncurses.h>
#include <panel.h>
#include <unistd.h>

#include "print.h"

void init() {
    char c = 0;
    int stop = 1;
    int error = 0, kadr = 0, reverse = 0;
    char *path = "sprites/wolf_2_1.txt";
    initscr();
    curs_set(0);
    nodelay(stdscr, TRUE);
    wolf *pwolf = NULL;
    while ((c = getch()) != EOF || stop != 0) {
        usleep(500000);
        clear();
        refresh();
        stop = get_key(c);
        if (c == 'd')
            reverse = 0;
        else if (c == 'a')
            reverse = 1;
        if (error == 0) {
            pwolf = import_wolf(path, &error);
            int **scene = form_scene(*pwolf, &error, kadr, reverse);
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

int get_key(char ch) {
    switch (ch) {
        case 'q':
            return 0;
    }
    return 1;
}
