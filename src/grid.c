#include "../include/grid.h"

char **allocate_grid(int n, int m) {
    char **screen = (char **)malloc(n * m * sizeof(char) + n * sizeof(char *));
    if (screen != NULL) {
        char *p = (char *)(screen + n);
        for (int i = 0; i < n; i++) 
			screen[i] = p + m * i;
    }
    return screen;
}

int load_initial_grid(char ***screen, int n, int m) {
    int succs = 0;
    int i = 0, j = 0;
    char c;

    while ((c = getchar()) != EOF && i < n) {
        if (c == '\n') {
            if (j != m) succs = 1;
            i++;
            j = 0;
        } else {
            if (j >= m || (c != ' ' && c != '#')) succs = 1;
            (*screen)[i][j] = c;
            j++;
        }
    }

    if (i != n) succs = 1;

    return succs;
}
