#include "Menu.hpp"
#include "Button.hpp"

Menu::Menu(Font *font) {
  this->font = font;
  Button *b = new Button(font, "SALUX", { 400, 400 });
  this->components = { b };
}

void Menu::draw(SDL_Renderer *renderer, int width, int height) {

  this->font->drawText(renderer, "ASTEROID", (width / 2) - 100,
                       (height / 2) - 100);

  // this->font->drawText(renderer, "Play", (width / 2) - 100, (height / 2) + 100);
  Button *b = (Button *) this->components[0];
  b->border = true;

  for (UIComponent *comp: this->components) {
    if (comp->enabled) { comp->draw(renderer); }
  }
}

Menu::~Menu() {
  for (UIComponent *comp : this->components) {
    delete comp;
  }
}
