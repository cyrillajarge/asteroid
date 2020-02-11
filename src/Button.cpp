#include "Button.hpp"


Button::Button() {

}

Button::Button(Font *font, std::string label, glm::vec2 label_pos) {
  this->font = font;
  this->label = label;
  this->label_pos = label_pos;
}

Button::Button(Font *font, std::string label, glm::vec2 label_pos, std::function<void()> handler) {
  this->font = font;
  this->label = label;
  this->handler = handler;
  this->label_pos = label_pos;
}

void Button::computeBox() {
  int end = this->font->getEndPos(this->label, this->label_pos.x);
  this->x = this->label_pos.x - this->padding.left;
  this->w = end - this->label_pos.x + this->padding.right;
}

void Button::draw(SDL_Renderer *renderer) {
  SDL_Rect r;
  r.x = this->x;
  r.y = this->y;
  r.h = this->h;
  r.w = this->w;

  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  SDL_RenderDrawRect(renderer, &r);
}