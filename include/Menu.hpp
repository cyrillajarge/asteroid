#ifndef MENU_H
#define MENU_H
#include "Font.hpp"
#include "SDL2/SDL.h"
#include "Sound/Sound.hpp"
#include "UI/UIComponent.hpp"
#include <string>
#include <unordered_map>
#include <vector>

class Menu {
public:
  Font *font;
  Sound *musicbg;
  std::unordered_map<std::string, UIComponent *> components;

public:
  Menu(Font *font);
  ~Menu();
  void draw(SDL_Renderer *renderer, int width, int height);
};

#endif