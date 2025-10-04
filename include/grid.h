#ifndef GRID_H

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#define GRID_WIDTH 78	// size of an actual image not considering frame
#define GRID_HEIGHT 23

char **allocate_grid(int n, int m);
int load_initial_grid(char ***screen, int n, int m);
#endif
