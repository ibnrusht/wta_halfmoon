/*
 * Created Date: Friday July 29th 2022
 * Author: Amir Khadiev
 * email: <ibn.rusht@gmail.com>
 * -----
 * Last Modified: Fri Aug 05 2022
 * Modified By: Amir Khadiev
 * -----
 * Copyright 2022 Amir Khadiev
 */
#include "objects.h"

#include <stdio.h>
#include <stdlib.h>

wolf *import_wolf(char *path, int *error) {
    wolf *p_wolf = NULL;
    FILE *fp = fopen(path, "r");
    if (fp) {
        p_wolf = malloc(sizeof(wolf));
        if (p_wolf) {
            (*p_wolf).matrix = calloc(Y_WOLF, sizeof(int *));
            if ((*p_wolf).matrix) {
                for (int i = 0; i < Y_WOLF; i++) {
                    (*p_wolf).matrix[i] = calloc(X_WOLF, sizeof(int));
                    if ((*p_wolf).matrix[i] == NULL) {
                        *error = 1;
                        break;
                    }
                }
                int i = 0;
                while (*error == 0 && feof(fp) == 0 && i < Y_WOLF) {
                    int num = 0, j = 0;
                    char c = 0;
                    while (fscanf(fp, "%d%c", &num, &c) == 2 && c == ' ' && j < X_WOLF) {
                        (*p_wolf).matrix[i][j] = num;
                        j++;
                    }
                    (*p_wolf).matrix[i][j] = num;
                    i++;
                }
                fclose(fp);
            } else {
                *error = 1;
                fclose(fp);
            }
        } else {
            *error = 1;
            fclose(fp);
        }
    } else {
        *error = 1;
    }
    return p_wolf;
}
