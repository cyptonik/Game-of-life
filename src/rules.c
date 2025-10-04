#include "../include/rules.h"

int count_live_neighbors(char **screen, int a, int b) {
    int sum = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nearx = (a + i + GRID_HEIGHT) % GRID_HEIGHT, neary = (b + j + GRID_WIDTH) % GRID_WIDTH;

            if (i == 0 && j == 0) 
				continue;

            if (screen[nearx][neary] == '#') 
				sum++;
        }
    }

    return sum;
}

void calculate_next_gen(char **screen, int n, int m, int *end) {
    char **next = allocate_grid(n, m);
    int count_dead = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            next[i][j] = ' ';
            if (screen[i][j] == ' ') count_dead++;
        }
    }

    if (count_dead < m * n) {
		determine_state(screen, next, n, m);
    } 
	else {
        *end = 1;
	}

    free(next);
}

void determine_state(char **screen, char** next, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (screen[i][j] == ' ' && count_live_neighbors(screen, i, j) == 3)
				next[i][j] = '#';

			else if (screen[i][j] == '#' && (count_live_neighbors(screen, i, j) < 2 || 
											 count_live_neighbors(screen, i, j) > 3))
				next[i][j] = ' ';

			else if (screen[i][j] == '#' &&
					 (count_live_neighbors(screen, i, j) == 2 || count_live_neighbors(screen, i, j) == 3))
				next[i][j] = '#';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			screen[i][j] = next[i][j];
		}
	}
}
