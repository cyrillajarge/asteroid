#ifndef MENU_H
#define MENU_H
#include <string>
#include "SDL2/SDL.h"

class Menu {
  private:
    std::string hello;
  public:
    Menu();
    ~Menu();
    void drawHello(SDL_Renderer *renderer);
};

#endif