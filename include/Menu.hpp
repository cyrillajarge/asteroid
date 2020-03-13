#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>
#include <unordered_map>
#include "SDL2/SDL.h"
#include "Font.hpp"
#include "UI/UIComponent.hpp"
#include "Sound/Sound.hpp"

class Menu {
  public:
    Font* font;
    Sound* musicbg;
    std::unordered_map<std::string, UIComponent *> components;

  public:
    Menu(Font* font);
    ~Menu();
    void draw(SDL_Renderer *renderer, int width, int height);
};

#endif