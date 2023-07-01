#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

int main(int argc, char* args[]) {
  if (SDL_Init(SDL_INIT_VIDEO) > 0)
    std::cout << "SDL Init has failed! D: Error Message: " << SDL_GetError() << std::endl;

  if (!IMG_Init(IMG_INIT_PNG))
    std::cout << "IMG Init has failed! D: Error Message: " << SDL_GetError() << std::endl;

  RenderWindow window("Sniffy Butt Fart", 1280, 720);

  bool running = true;

  SDL_Event event;

  while (running) {

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) running = false;
    }

  }

  window.cleanup();
  SDL_Quit();

  return 0;
}