#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow {
public:
  RenderWindow(const char* p_title, int p_w, int p_h);
  SDL_Texture* loadTexture(const char* p_filePath);
  void render(SDL_Texture* p_tex);
  void display();
  void clear();
  void cleanup();
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};