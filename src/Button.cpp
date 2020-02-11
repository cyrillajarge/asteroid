#include "Button.hpp"


Button::Button() {

}

Button::Button(Font *font, std::string label) {
  this->font = font;
  this->label = label;
}

Button::Button(Font *font, std::string label, std::function<void()> handler) {
  this->font = font;
  this->label = label;
  this->handler = handler;
}

void Button::computeBox() {

}