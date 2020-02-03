#ifndef FONT_H
#define FONT_H

#include "Hershey.hpp"
#include <iostream>
#include "SDL2/SDL.h"

class Font{
  public:

  public:
    Font();
    ~Font();
    void drawLetter(SDL_Renderer* renderer ,char letter);
};

#endif