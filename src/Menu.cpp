#include "Menu.hpp"
#include "UI/Button.hpp"
#include "UI/Checkbox.hpp"
#include "UI/PlainText.hpp"
#include "UI/TextInput.hpp"
#include <utility>

Menu::Menu(Font *font) {
  this->font = font;
}

void Menu::addButton(std::string tag, std::string label, glm::vec2 position){
  Button* b = new Button(label, position);
  this->components.insert({tag, b});
}

void Menu::addCheckbox(std::string tag, std::string label, glm::vec2 position){
  Checkbox* cb = new Checkbox(label, position);
  this->components.insert({tag, cb});
}

void Menu::addPlainText(std::string tag, std::string label, glm::vec2 position){
  PlainText* pt = new PlainText(label, position);
  this->components.insert({tag, pt});
}

void Menu::addTextInput(std::string tag, std::string label, glm::vec2 position){
  TextInput* ti = new TextInput(label, position);
  this->components.insert({tag, ti});
}

void Menu::draw(SDL_Renderer *renderer) {
  for (std::pair<std::string, UIComponent *> comp : this->components) {
    if ((comp.second)->enabled) {
      (comp.second)->draw(renderer);
    }
  }
}

Menu::~Menu() { this->components.clear(); }
