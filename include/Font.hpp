#ifndef FONT_H
#define FONT_H

#include "Hershey.hpp"
#include <iostream>
#include "SDL2/SDL.h"

class Font{
  public:
    double size;
    int spacing;
    SDL_Color color;
  public:
    Font();
    Font(double size);
    Font(SDL_Color color);
    ~Font();
    int drawLetter(SDL_Renderer *renderer , char letter, int x, int y);
    void drawText(SDL_Renderer *renderer, std::string text, int x, int y);
};

#endif