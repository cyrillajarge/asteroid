#ifndef BUTTON_H
#define BUTTON_H

#include "UIComponent.hpp"

class Button : public UIComponent {
  public:
    Button();
    Button(Font *font, std::string label);
    Button(Font *font, std::string label, std::function<void()> handler);
    ~Button();

  
  public:
    void draw(SDL_Renderer *renderer);

  
  private:
    void computeBox();

};

#endif