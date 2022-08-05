#ifndef SRC_MOVEMENTS_H_
#define SRC_MOVEMENTS_H_
#include "objects.h"
#include "print.h"

#define G 1   // acceleration of gravity
#define V0 3  // starting speed

void wolf_tail_movement(wolf *wolf, int state);
void wolf_movement(wolf *wolf, int move);
void y_position_change(int *position, int *v0);
void wolf_jump(int *position, int count, int *jump_state);
#endif  //  SRC_MOVEMENTS_H
