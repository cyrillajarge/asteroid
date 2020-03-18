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
  /**
   * @brief Font used in the menu
   *
   */
  Font *font;

  /**
   * @brief Sound for the menu
   *
   */
  Sound *musicbg;

  /**
   * @brief Map of UIComponents stored as pointers and identified by a string
   *
   */
  std::unordered_map<std::string, UIComponent *> components;

public:
  Menu(Font *font);
  ~Menu();
  void draw(SDL_Renderer *renderer, int width, int height);
};

#endif