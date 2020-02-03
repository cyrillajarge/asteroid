#include "Font.hpp"

Font::Font(){
  this->size = 28;
  this->spacing = 4;
  this->color = { 255, 255, 255, 255 };
}

Font::~Font(){

}

int Font::drawLetter(SDL_Renderer *renderer , char letter, int x, int y){
  int idx = letter - 32;
  if(idx < 0 || idx > 95){
    std::cerr << "Letter not supported!" << std::endl;
    exit(EXIT_FAILURE); 
  }
  else{
    SDL_SetRenderDrawColor(renderer,
      this->color.r,
      this->color.g,
      this->color.b,
      this->color.a
    );
    for(int i=2;i<111;i+=2){
      int x1val = simplex[idx][i];
      int y1val = simplex[idx][i+1];
      int x2val = simplex[idx][i+2];
      int y2val = simplex[idx][i+3];
      if(x1val != -1 && y1val != -1 && x2val != -1 && y2val != -1){
        SDL_RenderDrawLine(renderer, x2val+x, - y2val+y, x1val+x, - y1val+y); 
      }
    }
  }
  return simplex[idx][1];
}

void Font::drawText(SDL_Renderer *renderer, std::string text, int x, int y) {
  int xcur = x;
  for (char const c : text) {
    xcur += this->drawLetter(renderer, c, xcur, y);
    xcur += this->spacing;
  }
}