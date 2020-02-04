#include "Menu.hpp"

Menu::Menu(Font *font) { this->font = font; }

void Menu::draw(SDL_Renderer *renderer, int width, int height) {

  this->font->drawText(renderer, "ASTEROID", (width / 2) - 100,
                       (height / 2) - 100);

  this->font->drawText(renderer, "Play", (width / 2) - 100, (height / 2) + 100);
}

Menu::~Menu() {}
