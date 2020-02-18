#include "Menu.hpp"
#include "UI/Button.hpp"
#include "UI/PlainText.hpp"

Menu::Menu(Font *font) {
  this->font = font;
  PlainText *title = new PlainText("ASTEROID", {200,200});
  Button *b = new Button("PLAY", { 200, 200 });
  this->components = { b, title };
}

void Menu::draw(SDL_Renderer *renderer, int width, int height) {

  
  
  // SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  // SDL_RenderDrawPoint(renderer, width/2, height/2);

  Button *b = (Button *) this->components[0];
  b->border = true;
  b->border_color = {255,0,0,255};
  b->setPadding(20,20,20,20);
  b->center(width, height);

  PlainText *title = (PlainText *) this->components[1];
  title->center(width, height);
  title->setY(b->position.y - 100);

  for (UIComponent *comp: this->components) {
    if (comp->enabled) { comp->draw(renderer); }
  }
}

Menu::~Menu() {
  for (UIComponent *comp : this->components) {
    delete comp;
  }
}
