#include "../include/game_of_life.h"

int main() {
    char **scr = allocate_grid(GRID_HEIGHT, GRID_WIDTH);
    if (load_initial_grid(&scr, GRID_HEIGHT, GRID_WIDTH) != 1) {
        initscr();

		// make it multiplatform
        if (freopen("/dev/tty", "r", stdin) != NULL)
			run_game(scr);

        endwin();
        printf("Game over\n");
    } else
        printf("Incorrect input file\nThe file should be %dx%d (strange but that's how it is)\n", GRID_HEIGHT, GRID_WIDTH);

    free(scr);

    return 0;
}

void run_game(char **scr) {
	char c;
	int speed = MIN_SPEED;
	int end = 0;

	timeout(0);

	while (((c = getch()) != ' ') && end != 1) {
		if ((c == 'A' || c == 'a') && speed < MAX_SPEED)
			speed += STEP;

		else if ((c == 'Z' || c == 'z') && speed > MIN_SPEED)
			speed -= STEP;

		flushinp();

		if (speed != 0) 
			calculate_next_gen(scr, GRID_HEIGHT, GRID_WIDTH, &end);

		render_game_frame(scr, GRID_HEIGHT, GRID_WIDTH, speed);
	}
}
