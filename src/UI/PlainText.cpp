#include "UI/PlainText.hpp"

PlainText::PlainText(std::string label){
  this->label = label;
  this->position = glm::vec2(0,0);
  this->computeBox();
}

PlainText::PlainText(std::string label, glm::vec2 position){
  this->label = label;
  this->position = position;
  this->border = false;
  this->computeBox();
}

void PlainText::computeBox() {
  int end = this->font->getEndPos(this->label, this->position.x);
  this->xbox = this->position.x - this->padding.left;
  this->wbox = end - this->position.x + this->padding.right + this->padding.left;
  this->ybox = this->position.y - TEXT_HEIGHT - this->padding.top;
  this->hbox = TEXT_HEIGHT + 3 + this->padding.bottom + this->padding.top;
}

void PlainText::draw(SDL_Renderer *renderer){
  SDL_Rect r = { this->xbox, this->ybox, this->wbox, this->hbox };

  this->font->drawText(renderer, this->label, this->position.x, this->position.y);
  SDL_SetRenderDrawColor(renderer, this->border_color.x, this->border_color.y, this->border_color.z, this->border ? 255 : 0);
  SDL_RenderDrawRect(renderer, &r);
}