#include "Button.hpp"


Button::Button() {

}

Button::Button(Font *font, std::string labe, glm::vec2 label_pos) {
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