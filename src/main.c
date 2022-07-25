#include <stdio.h>

#include "objects.h"
#include "print.h"

int main() {
    wolf *pwolf = NULL;
    int error = 0;
    char *path = "sprites/wolf.txt";
    pwolf = import_wolf(path, &error);
    if (error == 0) {
            int **scene = form_scene(*pwolf, &error);
            if (error == 0) {
                print_scene(scene);
                clean_arrs(scene, Y_MAX);
            }
        clean_arrs((*pwolf).matrix, Y_WOLF);
    }
}
