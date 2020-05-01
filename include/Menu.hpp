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
  /**
   * @brief Adds a new Button to the menu
   * 
   * @param tag 
   * @param label 
   * @param position 
   */
  void addButton(std::string tag, std::string label, glm::vec2 position);
  /**
   * @brief Adds a new Checkbox to the menu
   * 
   * @param tag 
   * @param label 
   * @param position 
   */
  void addCheckbox(std::string tag, std::string label, glm::vec2 position);
  /**
   * @brief Adds a new PlainText component to the menu
   * 
   * @param tag 
   * @param label 
   * @param position 
   */
  void addPlainText(std::string tag, std::string label, glm::vec2 position);

  /**
   * @brief Adds a new TextInput to the menu
   * 
   * @param tag 
   * @param label 
   * @param position 
   */
  void addTextInput(std::string tag, std::string label, glm::vec2 position);

  /**
   * @brief Draws the menu
   * 
   * @param renderer 
   */
  void draw(SDL_Renderer *renderer);
};

#endif