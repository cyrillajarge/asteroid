#ifndef UICOMP_H
#define UICOMP_H

#include "Font.hpp"
#include "SDL2/SDL.h"
#include <iostream>

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

public:
  virtual void draw(SDL_Renderer *renderer);

  void setPadding(int top, int right, int bottom, int left) {
    this->padding = {top, right, bottom, left};
  }

  void setPadding(int v, int h) { this->padding = {v, h, v, h}; }

  void setPadding(int val) { this->padding = {val, val, val, val}; }

protected:
  int x, y, w, h;
  Font *font;
  std::string label;
  struct padding padding = {DEFAULT_PADDING, DEFAULT_PADDING, DEFAULT_PADDING,
                            DEFAULT_PADDING};
};

#endif