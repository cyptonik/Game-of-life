#include "../include/render.h"

void render_game_frame(char **screen, int n, int m, int speed) {
    noecho();
    curs_set(0);

    int j;
    for (int i = 1; i < n + 1; i++) {
        for (j = 1; j < m + 1; j++) {
            mvaddch(i, j, screen[i - 1][j - 1]);
        }
    }

    draw_border(0, 0);

    printw("\nControls: A - speed up, Z - speed down, SPACE - exit | Speed = %d\t", speed / STEP);

    refresh();
    napms(MAX_SPEED + 10 - speed);
}

void draw_border(int y1, int x1) {
    mvhline(y1, x1, '-', (GRID_WIDTH + 1) - x1);
    mvhline((GRID_HEIGHT + 1), x1, '-', (GRID_WIDTH + 1) - x1);
    mvvline(y1, x1, '|', GRID_HEIGHT + 1 - y1);
    mvvline(y1, (GRID_WIDTH + 1), '|', GRID_HEIGHT + 1 - y1);

    mvaddch(y1, x1, '+');
    mvaddch((GRID_HEIGHT + 1), x1, '+');
    mvaddch(y1, (GRID_WIDTH + 1), '+');
    mvaddch((GRID_HEIGHT + 1), (GRID_WIDTH + 1), '+');
}
