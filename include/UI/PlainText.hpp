#ifndef PLAINTEXT_HPP
#define PLAINTEXT_HPP

#include "UI/UIComponent.hpp"

class PlainText : public UIComponent{
  public:
    PlainText(std::string label, glm::vec2 position);
    void computeBox();
    void draw(SDL_Renderer *renderer);
};

#endif
