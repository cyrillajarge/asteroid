#include "UI/Button.hpp"

#define TEXT_HEIGHT 23

Button::Button(std::string label, glm::vec2 label_pos) {
  assert(UIComponent::default_font != nullptr);
  this->font = UIComponent::default_font;
  this->label = label;
  this->label_pos = label_pos;
  this->computeBox();
}

Button::Button(std::string label, glm::vec2 label_pos,
               std::function<void()> handler) {
  assert(UIComponent::default_font != nullptr);
  this->font = UIComponent::default_font;
  this->label = label;
  this->handler = handler;
  this->label_pos = label_pos;
  this->computeBox();
}

void Button::computeBox() {
  int end = this->font->getEndPos(this->label, this->label_pos.x);
  this->x = this->label_pos.x - this->padding.left;
  this->w = end - this->label_pos.x + this->padding.right + this->padding.left;
  this->y = this->label_pos.y - TEXT_HEIGHT - this->padding.top;
  this->h = TEXT_HEIGHT + 3 + this->padding.bottom + this->padding.top;
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

void Button::centerVertically(int height) {
    int buttonmiddley = TEXT_HEIGHT/2;
    int windmiddley = height/2;
    this->label_pos.y = windmiddley + buttonmiddley;
    this->computeBox();
  }

  void Button::centerHorizontally(int width) {
    int buttonmiddlex = (this->font->getEndPos(this->label, this->label_pos.x) - this->label_pos.x)/2;
    int windmiddlex = width/2;
    this->label_pos.x = windmiddlex - buttonmiddlex;
    this->computeBox();
  }

  void Button::center(int width, int height) {
    this->centerVertically(height);
    this->centerHorizontally(width);
  }

void Button::draw(SDL_Renderer *renderer) {
  SDL_Rect r = { this->x, this->y, this->w, this->h };

  this->font->drawText(renderer, this->label, this->label_pos.x, this->label_pos.y);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, this->border ? 255 : 0);
  SDL_RenderDrawRect(renderer, &r);
}