#include "Button.hpp"

Button::Button() {}

Button::Button(Font *font, std::string label, glm::vec2 label_pos) {
  this->font = font;
  this->label = label;
  this->label_pos = label_pos;
  this->computeBox();
}

Button::Button(Font *font, std::string label, glm::vec2 label_pos,
               std::function<void()> handler) {
  this->font = font;
  this->label = label;
  this->handler = handler;
  this->label_pos = label_pos;
  this->computeBox();
}

void Button::computeBox() {
  int end = this->font->getEndPos(this->label, this->label_pos.x);
  this->x = this->label_pos.x - this->padding.left;
  this->w = end - this->label_pos.x + this->padding.right + this->padding.left;
  this->y = this->label_pos.y - 50;
  this->h = this->label_pos.y - this->y + this->padding.bottom;
}

void Button::setX(int x) {
  this->label_pos.x = x;
  this->computeBox();
}

void Button::setY(int y) {
  this->label_pos.y = y;
  this->computeBox();
}

void Button::setPos(int x, int y) {
  this->label_pos = {x, y};
  this->computeBox();
}

void Button::draw(SDL_Renderer *renderer) {
  SDL_Rect r = { this->x, this->y, this->w, this->h };

  this->font->drawText(renderer, this->label, this->label_pos.x, this->label_pos.y);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, this->border ? 255 : 0);
  SDL_RenderDrawRect(renderer, &r);
}