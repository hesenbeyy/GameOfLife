#ifndef FUNCS_H
#define FUNCS_H

#include <SDL.h>
#include "macros.h"

void SDL_RenderDrawGrid(SDL_Renderer* renderer);
void change_gens(SDL_Renderer* renderer, int curr[WIDTH / CELL_SIZE][HEIGHT / CELL_SIZE], int next[WIDTH / CELL_SIZE][HEIGHT / CELL_SIZE]);

#endif