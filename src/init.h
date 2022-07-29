#ifndef SRC_INIT_H_
#define SRC_INI_H_

void init();
int get_key(char ch, int *reverse, int *position, int* move);
void state_change(int *tail_state, int *star_state, int *move, int *count);

#endif  // SRC_INIT_H_
