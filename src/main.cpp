#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

struct Entity {
  SDL_Texture* texture;
  SDL_Rect* src_rect;
  SDL_Rect* dest_rect;
};

int main(int argc, char* args[]) {
  if (SDL_Init(SDL_INIT_VIDEO) > 0) std::cout << "SDL Init has failed! D: Error Message: " << SDL_GetError() << std::endl;
  if (!IMG_Init(IMG_INIT_PNG)) std::cout << "IMG Init has failed! D: Error Message: " << SDL_GetError() << std::endl;

  SDL_Window* window = SDL_CreateWindow("Sniffy Butt Fart", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 512*2, 512*2, SDL_WINDOW_SHOWN);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // SDL_Texture* grassTexture = IMG_LoadTexture(renderer, "./res/img/grass.png");
  SDL_Texture* dirtTexture = IMG_LoadTexture(renderer, "./res/img/dirt.png");
  SDL_Texture* grassTileTexture = IMG_LoadTexture(renderer, "./res/img/grassTile.png");
  SDL_Texture* baseTexture = IMG_LoadTexture(renderer, "./res/img/base.png");

  const int fps = 60;
  const int frameDelay = 1000 / fps;
  // Uint32 lastFrameStart = 0;
  Uint32 frameStart = 0;
  int frameTime;

  std::vector<Entity> renderList = std::vector<Entity>();

  const int baseLocation = 7*64;

  int map[16][16] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  };

  // maybe add 16X16 map? not really sure lol
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      int tile = map[i][j];


      if (tile == 0) renderList.push_back({ dirtTexture, new SDL_Rect({0, 0, 32, 32}), new SDL_Rect({j*64, i*64, 64, 64}) });
      else if (tile == 1) renderList.push_back({ grassTileTexture, new SDL_Rect({0, 0, 32, 32}), new SDL_Rect({j*64, i*64, 64, 64}) });
    }
  }
  renderList.push_back({ baseTexture, new SDL_Rect({0, 0, 64, 64}), new SDL_Rect({baseLocation, baseLocation-16, 128, 128}) });

  bool running = true;
  SDL_Event event;

  while (running) {
    // lastFrameStart = frameStart;
    frameStart = SDL_GetTicks();

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) running = false;
    }



    SDL_RenderClear(renderer);
    for (size_t i = 0; i < renderList.size(); i++) {
      Entity entity = renderList[i];
      SDL_RenderCopy(renderer, entity.texture, entity.src_rect, entity.dest_rect);

    }
    SDL_RenderPresent(renderer);

    // Output actual framerate
    // double a = (frameStart - lastFrameStart);
    // if (a == 0) a = 1;
    // std::cout << 1000 / a << std::endl;

    frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}