#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "UI/Clickable.hpp"
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"

class Checkbox : public Clickable{
  public:
    /**
     * Checkbox status
     */
    bool checked = false;

    Checkbox(std::string label);
    Checkbox(std::string label, glm::vec2 position);
    Checkbox(std::string label, glm::vec2 position,
          std::function<void()> handler);

    void computeBox();
    void draw(SDL_Renderer* renderer);
};

#endif