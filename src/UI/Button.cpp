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

// void Button::setX(int x) {
//   this->label_pos.x = x;
//   this->computeBox();
// }

// void Button::setY(int y) {
//   this->label_pos.y = y;
//   this->computeBox();
// }

// void Button::setPos(int x, int y) {
//   this->label_pos = {x, y};
//   this->computeBox();
// }

// void Button::centerVertically(int height) {
//     int buttonmiddley = TEXT_HEIGHT/2;
//     int windmiddley = height/2;
//     this->label_pos.y = windmiddley + buttonmiddley;
//     this->computeBox();
//   }

//   void Button::centerHorizontally(int width) {
//     int buttonmiddlex = (this->font->getEndPos(this->label, this->label_pos.x) - this->label_pos.x)/2;
//     int windmiddlex = width/2;
//     this->label_pos.x = windmiddlex - buttonmiddlex;
//     this->computeBox();
//   }

//   void Button::center(int width, int height) {
//     this->centerVertically(height);
//     this->centerHorizontally(width);
//   }

void Button::draw(SDL_Renderer *renderer) {
  SDL_Rect r = { this->xbox, this->ybox, this->wbox, this->hbox };

  this->font->drawText(renderer, this->label, this->position.x, this->position.y);
  SDL_SetRenderDrawColor(renderer, this->border_color.x, this->border_color.y, this->border_color.z, this->border ? 255 : 0);
  SDL_RenderDrawRect(renderer, &r);
}