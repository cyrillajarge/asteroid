#include "UI/Button.hpp"

Button::Button(std::string label, glm::vec2 label_pos) {
  this->label = label;
  this->position = label_pos;
  this->computeBox();
}

Button::Button(std::string label, glm::vec2 label_pos,
               std::function<void()> handler) {
  this->label = label;
  this->position = label_pos;
  this->handler = handler;
  this->computeBox();
}

void Button::computeBox() {
  int end = this->font->getEndPos(this->label, this->position.x);
  this->xbox = this->position.x - this->padding.left;
  this->wbox = end - this->position.x + this->padding.right + this->padding.left;
  this->ybox = this->position.y - TEXT_HEIGHT - this->padding.top;
  this->hbox = TEXT_HEIGHT + 3 + this->padding.bottom + this->padding.top;
}

void Button::draw(SDL_Renderer *renderer) {
  SDL_Rect r = { this->xbox, this->ybox, this->wbox, this->hbox };

  this->font->drawText(renderer, this->label, this->position.x, this->position.y);
  SDL_SetRenderDrawColor(renderer, this->border_color.x, this->border_color.y, this->border_color.z, this->border ? 255 : 0);
  SDL_RenderDrawRect(renderer, &r);
}