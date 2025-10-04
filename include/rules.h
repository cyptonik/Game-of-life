#ifndef RULES_H

#include "grid.h"

int count_live_neighbors(char **screen, int n, int m);
void calculate_next_gen(char **screen, int n, int m, int *end);
void determine_state(char **screen, char** next, int n, int m);
#endif
