#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include <sys/time.h>

#include "algo_utils.h"
#include "algo_sort.h"
#include "algo_2d.h"
#include "data_structures/linked_list.h"
#include "testing/algobenchs.h"

#define LINUX_BENCH

using namespace std;
#include "SDL2/SDL.h"

int main(int argc, char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow(
    "SDL2Test",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    640,
    480,
    0
  );

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  SDL_Delay(3000);

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

