#include "UI/Checkbox.hpp"

Checkbox::Checkbox(std::string label){
  this->label = label;
  this->position = glm::vec2(0,0);
  this->computeBox();
}

Checkbox::Checkbox(std::string label, glm::vec2 position){
  this->label = label;
  this->position = position;
  this->computeBox();
}

Checkbox::Checkbox(std::string label, glm::vec2 position,
          std::function<void()> handler){
  this->label = label;
  this->position = position;
  this->handler = handler;
  this->computeBox();
}

void Checkbox::computeBox(){
  int end = this->font->getEndPos(this->label, this->position.x);
  this->xbox = this->position.x - this->padding.left;
  this->wbox = end - this->position.x + this->padding.right + this->padding.left;
  this->ybox = this->position.y - TEXT_HEIGHT - this->padding.top;
  this->hbox = TEXT_HEIGHT + 3 + this->padding.bottom + this->padding.top;

  this->wbox += 40;
}

void Checkbox::draw(SDL_Renderer* renderer){
  SDL_Rect r = { this->xbox, this->ybox, this->wbox, this->hbox };

  // For label
  int text_width = this->font->getEndPos(this->label, this->position.x) - this->position.x + 20;
  this->font->drawText(renderer, this->label, this->position.x, this->position.y);

  SDL_Rect check = {static_cast<int>(this->position.x) + text_width, static_cast<int>(this->position.y) - TEXT_HEIGHT, 20, 20};

  // For checkbox
  SDL_SetRenderDrawColor(renderer, 255,255,255, 255);
  (checked)? SDL_RenderFillRect(renderer, &check) : SDL_RenderDrawRect(renderer, &check);

  // For border
  SDL_SetRenderDrawColor(renderer, this->border_color.x, this->border_color.y, this->border_color.z, this->border ? 255 : 0);
  SDL_RenderDrawRect(renderer, &r);
}