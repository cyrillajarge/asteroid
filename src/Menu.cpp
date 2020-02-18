#include "Menu.hpp"
#include "UI/Button.hpp"

Menu::Menu(Font *font) {
  this->font = font;
  Button *b = new Button("PLAY", { 20, 20 });
  this->components = { b };
}

void Menu::draw(SDL_Renderer *renderer, int width, int height) {

  this->font->drawText(renderer, "ASTEROID", (width / 2) - 100,
                       (height / 2) - 100);
  
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  SDL_RenderDrawPoint(renderer, width/2, height/2);

  // this->font->drawText(renderer, "Play", (width / 2) - 100, (height / 2) + 100);
  Button *b = (Button *) this->components[0];
  b->border = true;
  b->setPadding(20,20,20,20);
  b->center(width, height);

  for (UIComponent *comp: this->components) {
    if (comp->enabled) { comp->draw(renderer); }
  }
}

Menu::~Menu() {
  for (UIComponent *comp : this->components) {
    delete comp;
  }
}
