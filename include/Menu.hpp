#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>
#include "SDL2/SDL.h"
#include "Font.hpp"
#include "UI/UIComponent.hpp"

class Menu {
  public:
    Font* font;
    std::vector<UIComponent *> components;

  public:
    Menu(Font* font);
    ~Menu();
    void draw(SDL_Renderer *renderer, int width, int height);
};

#endif