#include "Font.hpp"
#define DEFAULT_SPACING 4

Font::Font() {
  this->size = 1;
  this->spacing = 4;
  this->color = {255, 255, 255, 255};
}

Font::Font(double size) {
  this->size = size;
  this->spacing = DEFAULT_SPACING;
  this->color = {255, 255, 255, 255};
}

Font::Font(SDL_Color color) {
  this->size = 1;
  this->spacing = DEFAULT_SPACING;
  this->color = color;
}

Font::~Font() {}

int Font::getLetterWidth(char letter) {
  int idx = letter - 32;
  if (idx < 0 || idx > 95) {
    std::cerr << "Letter not supported!" << std::endl;
    exit(EXIT_FAILURE);
  }
  return simplex[idx][1] * this->size;
}

int Font::drawLetter(SDL_Renderer *renderer, char letter, int x, int y) {
  int idx = letter - 32;
  if (idx < 0 || idx > 95) {
    std::cerr << "Letter not supported!" << std::endl;
    exit(EXIT_FAILURE);
  } else {
    SDL_SetRenderDrawColor(renderer, this->color.r, this->color.g,
                           this->color.b, this->color.a);
    for (int i = 2; i <= 108; i += 2) {
      int x1val = simplex[idx][i];
      int y1val = simplex[idx][i + 1];
      int x2val = simplex[idx][i + 2];
      int y2val = simplex[idx][i + 3];
      if (x1val != -1 && y1val != -1 && x2val != -1 && y2val != -1) {
        SDL_RenderDrawLine(renderer, x1val * this->size + x,
                           -y1val * this->size + y, x2val * this->size + x,
                           -y2val * this->size + y);
      }
    }
  }
  return simplex[idx][1] * this->size;
}

int Font::drawText(SDL_Renderer *renderer, std::string text, int x, int y) {
  int xcur = x;
  for (char const c : text) {
    xcur += this->drawLetter(renderer, c, xcur, y);
    xcur += this->spacing;
  }
  return xcur - this->spacing;
}

int Font::getEndPos(std::string text, int x) {
  int xcur = x;
  for (char const c : text) {
    xcur += this->getLetterWidth(c);
    xcur += this->spacing;
  }
  return xcur - this->spacing;
}

int Font::getWidth(std::string text) {
  int length = 0;
  for (char const c : text) {
    length += this->getLetterWidth(c);
  }
  return length;
}