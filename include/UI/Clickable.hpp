#ifndef CLICKABLE_H
#define CLICKABLE_H

#include "UI/UIComponent.hpp"
#include <functional>

class Clickable : public UIComponent {
  public:
    std::function<void()> handler;

};


#endif