#include "Menu.hpp"
#include "UI/Button.hpp"
#include "UI/PlainText.hpp"
#include "UI/Checkbox.hpp"

Menu::Menu(Font *font) {
  this->font = font;
  PlainText *title = new PlainText("ASTEROID", {200,200});
  Button *b = new Button("PLAY", { 200, 200 });
  Checkbox *music = new Checkbox("MUSIC", {400,400});
  Checkbox *sounds = new Checkbox("SOUNDS", {400,400});
  this->components = { b, title, music, sounds };
  this->main_components["title"] = title;
  this->main_components["play"] = b;
}

void Menu::renameComponent(std::string key, std::string val) {
  this->main_components[key]->label = val;
}

void Menu::draw(SDL_Renderer *renderer, int width, int height) {

  
  
  // SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  // SDL_RenderDrawPoint(renderer, width/2, height/2);

  Button *b = (Button *) this->components[0];
  b->border = true;
  b->border_color = {255,0,0,255};
  // b->setPadding(20,20,20,20);
  b->center(width, height);
  // b->setY(b->position.y + 50);

  PlainText *title = (PlainText *) this->components[1];
  title->center(width, height);
  title->setY(b->position.y - 200);

  Checkbox *music = (Checkbox*) this->components[2];
  music->border = true;
  music->border_color = {0,255,0,255};
  music->center(width, height);
  music->setY(b->position.y + 50);

  Checkbox *sounds = (Checkbox*) this->components[3];
  sounds->border = true;
  sounds->border_color = {0,0,255,255};
  sounds->center(width, height);
  sounds->setY(music->position.y + 50);

  for (UIComponent *comp: this->components) {
    if (comp->enabled) { comp->draw(renderer); }
  }
}

Menu::~Menu() {
  for (UIComponent *comp : this->components) {
    delete comp;
  }
}
