#ifndef CLICKABLE_H
#define CLICKABLE_H

#include "UI/UIComponent.hpp"
#include <functional>

class Clickable : public UIComponent {
  public:
    std::function<void()> handler;
  
  public:
    SDL_bool isIn(int x, int y) {
      SDL_Rect r = {this->xbox, this->ybox, this->wbox, this->hbox};
      SDL_Point p = {x, y};
      return SDL_PointInRect(&p, &r);
    }

};


#endif