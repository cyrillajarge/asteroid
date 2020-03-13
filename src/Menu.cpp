#include "Menu.hpp"
#include "UI/Button.hpp"
#include "UI/PlainText.hpp"
#include "UI/Checkbox.hpp"
#include <utility>

Menu::Menu(Font *font) {
  this->font = font;
  PlainText *title = new PlainText("ASTEROID", {200,200});
  Button *b = new Button("PLAY", { 200, 200 });
  Checkbox *music = new Checkbox("MUSIC", {400,400});
  Checkbox *sounds = new Checkbox("SOUNDS", {400,400});
  PlainText *score = new PlainText("No score yet", { 400, 400 });
  score->enabled = false;
  this->components = {
    { "title", title },
    { "play", b },
    { "music", music },
    { "sounds", sounds },
    { "score", score }
  };
}

void Menu::draw(SDL_Renderer *renderer, int width, int height) {
  
  // SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  // SDL_RenderDrawPoint(renderer, width/2, height/2);

  Button *b = static_cast<Button *>(this->components["play"]);
  b->border = true;
  b->border_color = {255,0,0,255};
  // b->setPadding(20,20,20,20);
  b->center(width, height);
  // b->setY(b->position.y + 50);

  PlainText *title = static_cast<PlainText *>(this->components["title"]);
  title->center(width, height);
  title->setY(b->position.y - 200);

  Checkbox *music = static_cast<Checkbox *>(this->components["music"]);
  music->border = true;
  music->border_color = {0,255,0,255};
  music->center(width, height);
  music->setY(b->position.y + 50);

  Checkbox *sounds = static_cast<Checkbox *>(this->components["sounds"]);
  sounds->border = true;
  sounds->border_color = {0,0,255,255};
  sounds->center(width, height);
  sounds->setY(music->position.y + 50);

  PlainText *score = static_cast<PlainText *>(this->components["score"]);
  score->center(width, height);
  score->setY(sounds->position.y + 100);

  for (std::pair<std::string, UIComponent *> comp: this->components) {
    if ((comp.second)->enabled) { (comp.second)->draw(renderer); }
  }
}

Menu::~Menu() {
  this->components.clear();
}
