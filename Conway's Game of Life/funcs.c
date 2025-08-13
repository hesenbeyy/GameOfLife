#include <stdio.h>
#include <SDL.h>
#include "macros.h"
#include "funcs.h"

void SDL_RenderDrawGrid(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(GREY_COLOR);

	for (int x = 0; x <= WIDTH; x += CELL_SIZE) {
		SDL_RenderDrawLine(renderer, x, 0, x, HEIGHT);
	}
	
	for (int y = 0; y <= HEIGHT; y += CELL_SIZE) {
		SDL_RenderDrawLine(renderer, 0, y, WIDTH, y);
	}
}

void change_gens(SDL_Renderer* renderer, int curr[WIDTH / CELL_SIZE][HEIGHT / CELL_SIZE], int next[WIDTH / CELL_SIZE][HEIGHT / CELL_SIZE]) {
	SDL_SetRenderDrawColor(BLACK_COLOR);
	//SDL_RenderClear(renderer);
	for (int x = 0; x < WIDTH / CELL_SIZE; x++) {
		for (int y = 0; y < HEIGHT / CELL_SIZE; y++){

			int dir_left_up = 0;
			int dir_left = 0;
			int dir_left_down = 0;
			int dir_down = 0;
			int dir_right_down = 0;
			int dir_right = 0;
			int dir_right_up = 0;
			int dir_up = 0;
			
			if (x - 1 >= 0) dir_left = curr[x - 1][y];
			if (x + 1 <= WIDTH / CELL_SIZE - 1) dir_right = curr[x + 1][y];
			if (y - 1 >= 0) dir_up = curr[x][y - 1];
			if (y + 1 <= HEIGHT / CELL_SIZE - 1) dir_down = curr[x][y + 1];
			if (y - 1 >= 0 && x - 1 >= 0) dir_left_up = curr[x - 1][y - 1];
			if (y + 1 <= HEIGHT / CELL_SIZE - 1 && x + 1 <= WIDTH / CELL_SIZE - 1) dir_right_down = curr[x + 1][y + 1];
			if (y - 1 >= 0 && x + 1 <= WIDTH / CELL_SIZE - 1) dir_right_up = curr[x + 1][y - 1];
			if (y + 1 <= HEIGHT / CELL_SIZE - 1 && x - 1 >= 0) dir_left_down = curr[x - 1][y + 1];

			int sum = NEIGHBOUR_SUM;

			if (curr[x][y]) {  // alive
				if (sum == 2 || sum == 3) {
					// stays alive
					next[x][y] = 1;
				}
				else if (sum < 2 || sum > 3) {
					// dies
					next[x][y] = 0;
				}
			} else {  // dead
				if (sum == 3) {
					// borns
					next[x][y] = 1;
				}
				else {
					// stays dead
					next[x][y] = 0;
				}
			}
		}
	}
}