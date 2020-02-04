#ifndef MENU_H
#define MENU_H
#include <string>
#include "SDL2/SDL.h"
#include "Font.hpp"

class Menu {
  public:
    Font* font;

  public:
    Menu(Font* font);
    ~Menu();
    void draw(SDL_Renderer *renderer, int width, int height);
};

#endif