#ifndef MENU_H
#define MENU_H
#include "Font.hpp"
#include "SDL2/SDL.h"
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
   * @brief Map of UIComponents stored as pointers and identified by a string
   *
   */
  std::unordered_map<std::string, UIComponent *> components;

public:
  Menu(Font *font);
  ~Menu();

  void addButton(std::string tag, std::string label, glm::vec2 position);
  void addCheckbox(std::string tag, std::string label, glm::vec2 position);
  void addPlainText(std::string tag, std::string label, glm::vec2 position);
  void addTextInput(std::string tag, std::string label, glm::vec2 position);
  void draw(SDL_Renderer *renderer);
};

#endif