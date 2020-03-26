#include "UI/TextInput.hpp"
#include "SDL2/SDL.h"

TextInput::TextInput(std::string label, glm::vec2 position){
  this->label = label;
  this->position = position;
  this->border = false;
  this->computeBox();
};

void TextInput::addLetter(SDL_Event e){
  input += e.text.text;
}

void TextInput::removeLetter(SDL_Event e){
  if (e.key.keysym.sym == SDLK_BACKSPACE && input.size()) {
    input.pop_back();
  }
}

void TextInput::computeBox(){
  int end1 = this->font->getEndPos(this->label, this->position.x);
  int end2 = this->font->getWidth(this->input);
  int end = end1 + end2;
  this->xbox = this->position.x - this->padding.left;
  this->wbox = end - this->position.x + this->padding.right + this->padding.left;
  this->ybox = this->position.y - TEXT_HEIGHT - this->padding.top;
  this->hbox = TEXT_HEIGHT + 3 + this->padding.bottom + this->padding.top;
}

void TextInput::draw(SDL_Renderer *renderer){
  SDL_Rect r = { this->xbox, this->ybox, this->wbox, this->hbox };

  this->font->drawText(renderer, this->label + this->input, this->position.x, this->position.y);
  SDL_SetRenderDrawColor(renderer, this->border_color.x, this->border_color.y, this->border_color.z, this->border ? 255 : 0);
  SDL_RenderDrawRect(renderer, &r);
}