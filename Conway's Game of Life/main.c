#include <stdio.h>
#include <string.h>
#include <SDL.h>
#include "macros.h"
#include "funcs.h"

int main() {

	printf("Welcome to the Conway's Game of Life!\n");
	srand(time(NULL));
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Conway's Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_RenderDrawGrid(renderer);
	SDL_RenderPresent(renderer);

	int current_gen[WIDTH / CELL_SIZE][HEIGHT / CELL_SIZE] = { 0 };
	int next_gen[WIDTH / CELL_SIZE][HEIGHT / CELL_SIZE] = { 0 };

	SDL_Event e;
	int running = 1;
	int init = 1;
	while (running) {
		SDL_SetRenderDrawColor(BLACK_COLOR);
		SDL_RenderClear(renderer);
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				running = 0;
			}
		}

		if (init) {
			for (int x = 0; x < WIDTH / CELL_SIZE; x++) {
				for (int y = 0; y < HEIGHT / CELL_SIZE; y++) {
					current_gen[x][y] = rand() % 2;
					SDL_Rect current_rect = { x * CELL_SIZE,y * CELL_SIZE,CELL_SIZE,CELL_SIZE };
					if (current_gen[x][y]) {
						SDL_SetRenderDrawColor(WHITE_COLOR);
						SDL_RenderFillRect(renderer, &current_rect);
					}
				}
			}
			init = 0;
			//SDL_RenderDrawGrid(renderer);
			SDL_RenderPresent(renderer);
			SDL_Delay(50);
			continue;
		}

		change_gens(renderer, current_gen, next_gen);        // most important function of the game frfr
		for (int x = 0; x < WIDTH / CELL_SIZE; x++) {
			for (int y = 0; y < HEIGHT / CELL_SIZE; y++) {
				SDL_Rect next_rect = { x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE };
				if (next_gen[x][y]) {
					SDL_SetRenderDrawColor(WHITE_COLOR);
					SDL_RenderFillRect(renderer, &next_rect);
				}
			}
		}
		memcpy(current_gen, next_gen, sizeof(current_gen));
	
		//SDL_RenderDrawGrid(renderer);
		SDL_RenderPresent(renderer);
		SDL_Delay(50);
		
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}