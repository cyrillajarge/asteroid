#include "UI/UIComponent.hpp"

Font *UIComponent::font = nullptr;

void UIComponent::setPadding(int top, int right, int bottom, int left) {
  this->padding = {top, right, bottom, left};
  this->computeBox();
}

void UIComponent::setPadding(int v, int h) {
  this->padding = {v, h, v, h};
  this->computeBox();
}

void UIComponent::setPadding(int val) {
  this->padding = {val, val, val, val};
  this->computeBox();
}

void UIComponent::setX(int x){
  this->position.x = x;
  this->computeBox();
}

void UIComponent::setY(int y){
  this->position.y = y;
  this->computeBox();
}

void UIComponent::moveX(int x){
  this->position.x += x;
  this->computeBox();
}

void UIComponent::moveY(int y){
  this->position.y += y;
  this->computeBox();
}

void UIComponent::setPosition(int x, int y){
  this->position = {x,y};
  this->computeBox();
}

void UIComponent::centerVertically(int height) {
  int elementMiddleY = this->hbox/2;
  int windowMiddleY = height/2;
  this->position.y = windowMiddleY - elementMiddleY;
  this->computeBox();
}

void UIComponent::centerHorizontally(int width) {
  int buttonMiddleX = this->wbox/2;
  int windowMiddleX = width/2;
  this->position.x = windowMiddleX - buttonMiddleX;
  this->computeBox();
}

void UIComponent::center(int width, int height) {
  this->centerHorizontally(width);
  this->centerVertically(height);
  this->computeBox();
}