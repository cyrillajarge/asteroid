#ifndef FONT_H
#define FONT_H

#include "Hershey.hpp"
#include "SDL2/SDL.h"
#include <iostream>

class Font {
public:
  double size;
  int spacing;
  SDL_Color color;

public:
  Font();
  Font(double size);
  Font(SDL_Color color);
  ~Font();
  int drawLetter(SDL_Renderer *renderer, char letter, int x, int y);
  int drawText(SDL_Renderer *renderer, std::string text, int x, int y);
  int getLetterWidth(char letter);
  int getEndPos(std::string text, int x);
};

#endif