#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "UI/Clickable.hpp"
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"

class Checkbox : public Clickable{
  public:
    bool checked = false;

  public:
    Checkbox(std::string label, glm::vec2 position);
    Checkbox(std::string label, glm::vec2 position,
          std::function<void()> handler);

  public:
    void computeBox();
    void draw(SDL_Renderer* renderer);
};

#endif