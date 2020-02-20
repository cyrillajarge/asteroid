#ifndef BUTTON_H
#define BUTTON_H

#include "UI/Clickable.hpp"
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"

class Button : public Clickable {
  public:
    Button(std::string label, glm::vec2 label_pos);
    Button(std::string label, glm::vec2 label_pos,
          std::function<void()> handler);
    // ~Button();

  public:
    void computeBox();
    void draw(SDL_Renderer *renderer);
};

#endif