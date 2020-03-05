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
  private:
    std::unordered_map<std::string, UIComponent *> main_components;
  public:
    Font* font;
    Sound* musicbg;
    std::vector<UIComponent *> components;

  public:
    Menu(Font* font);
    ~Menu();
    void renameComponent(std::string key, std::string val);
    // void gameOver(SDL_Renderer *renderer, int width, int height);
    void draw(SDL_Renderer *renderer, int width, int height);
};

#endif