#ifndef UICOMP_H
#define UICOMP_H

#include "Font.hpp"
#include "SDL2/SDL.h"
#include <iostream>
#include <functional>

#define DEFAULT_PADDING 10

struct padding {
  int top;
  int right;
  int bottom;
  int left;
};

class UIComponent {
public:
  std::function<void()> handler;
  bool enabled = true;

public:
  virtual void draw(SDL_Renderer *renderer) = 0;

  void setPadding(int top, int right, int bottom, int left) {
    this->padding = {top, right, bottom, left};
  }

  void setPadding(int v, int h) { this->padding = {v, h, v, h}; }

  void setPadding(int val) { this->padding = {val, val, val, val}; }

  virtual ~UIComponent() {}

  SDL_bool isIn(int x, int y) {
    SDL_Rect r = {this->x, this->y, this->w, this->h};
    SDL_Point p = {x, y};
    return SDL_PointInRect(&p, &r);
  }

protected:
  int x, y, w, h;
  Font *font;
  std::string label;
  struct padding padding = {DEFAULT_PADDING, DEFAULT_PADDING, DEFAULT_PADDING,
                            DEFAULT_PADDING};
};

#endif