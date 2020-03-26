#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include <iostream>
#include "UI/UIComponent.hpp"

class TextInput : public UIComponent{
  public:
    std::string input = " ";

  public:
    TextInput(std::string label, glm::vec2 position);
    void addLetter(SDL_Event e);
    void removeLetter(SDL_Event e);
    void computeBox();
    void draw(SDL_Renderer *renderer);
};

#endif