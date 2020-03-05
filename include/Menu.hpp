#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>
#include "SDL2/SDL.h"
#include "Font.hpp"
#include "UI/UIComponent.hpp"
#include "Sound/Sound.hpp"

class Menu {
  public:
    Font* font;
    Sound* musicbg;
    std::vector<UIComponent *> components;

  public:
    Menu(Font* font);
    ~Menu();
    void setTitle(std::string t);
    // void gameOver(SDL_Renderer *renderer, int width, int height);
    void draw(SDL_Renderer *renderer, int width, int height);
};

#endif