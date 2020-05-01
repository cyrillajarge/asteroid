#ifndef CLICKABLE_H
#define CLICKABLE_H

#include "UI/UIComponent.hpp"
#include <functional>

class Clickable : public UIComponent {
  public:
  /**
   * @brief Function that defines the comportment when element is clicked
   */
    std::function<void()> handler;
  
  public:
    /**
     * @brief Checks if coordinates are inside the bounding box
     * 
     * @param x
     * @param y
     */
    SDL_bool isIn(int x, int y) {
      SDL_Rect r = {this->xbox, this->ybox, this->wbox, this->hbox};
      SDL_Point p = {x, y};
      return SDL_PointInRect(&p, &r);
    }

};


#endif