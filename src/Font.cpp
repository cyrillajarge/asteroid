#include "Font.hpp"

Font::Font(){

}

Font::~Font(){

}

void Font::drawLetter(SDL_Renderer* renderer , char letter){
  int letter_ascii = (int)letter;
  if(letter_ascii < 32 || letter_ascii > 126){
    std::cerr << "Letter not supported!" << std::endl;
    exit(EXIT_FAILURE); 
  }
  else{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255 );
    for(int i=2;i<111;i+=2){
      int x1val = simplex[letter_ascii-32][i];
      int y1val = simplex[letter_ascii-32][i+1];
      int x2val = simplex[letter_ascii-32][i+2];
      int y2val = simplex[letter_ascii-32][i+3];
      if(x1val != -1 && y1val != -1 && x2val != -1 && y2val != -1){
        SDL_RenderDrawLine(renderer, x2val+10, y2val+10, x1val+10, y1val+10); 
      }
    }
  }
}