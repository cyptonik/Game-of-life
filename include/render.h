#ifndef RENDER_H

#include "grid.h"

#define STEP 10
#define MAX_SPEED 200
#define MIN_SPEED 0

void render_game_frame(char **screen, int n, int m, int speed);
void draw_border(int y1, int x1);
#endif
