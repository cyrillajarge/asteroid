#ifndef UICOMP_H
#define UICOMP_H

#include "Font.hpp"
#include "SDL2/SDL.h"
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"
#include <iostream>

#define DEFAULT_PADDING 10
#define TEXT_HEIGHT 23

struct padding {
  int top;
  int right;
  int bottom;
  int left;
};

class UIComponent {
  public:
    bool enabled = true;
    glm::vec2 position;
    int xbox, ybox, wbox, hbox;
    struct padding padding = {DEFAULT_PADDING, DEFAULT_PADDING, DEFAULT_PADDING,
                              DEFAULT_PADDING};
    std::string label;
    static Font *font;
    bool border = false;
    glm::vec4 border_color = {255,255,255,255};

  public:
    void setPadding(int top, int right, int bottom, int left);
    void setPadding(int v, int h);
    void setPadding(int val);
    void setX(int x);
    void setY(int y);
    void moveX(int x);
    void moveY(int y);
    void setPosition(int x, int y);
    void centerVertically(int height);
    void centerHorizontally(int width);
    void center(int height, int width);
    virtual void draw(SDL_Renderer *renderer) = 0;
    virtual void computeBox() = 0;
    virtual ~UIComponent() {}

};

#endif