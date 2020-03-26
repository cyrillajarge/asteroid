#include "InputManager.hpp"
#include <iostream>

InputManager::InputManager(input_mapping_t kind) {
  this->initMapper(kind);
}

void InputManager::attach(std::shared_ptr<Spaceship> s) {
  this->spaceship = s;
}

void InputManager::process(int current_time) {
  std::shared_ptr<Spaceship> ship = this->spaceship.lock();

  if (!ship) { 
    std::cerr << "Spaceship missing from InputManager" << std::endl;
    return; 
  }
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[this->mapper.left]) {
    this->deltaRotation = -DELTA_ANGLE;
  }
  if (keystates[this->mapper.right]) {
    this->deltaRotation = DELTA_ANGLE;
  }
  if (keystates[this->mapper.prop]) {
    ship->activateBoost();
  }
  if (keystates[this->mapper.fire]) {
    if (current_time - this->last_shot > 1000 / ship->weapon->fire_rate) {
      ship->weapon->fire();
      this->last_shot = current_time;
    }
  }
  if (keystates[this->mapper.spec]) {
    ship->weapon->fireSpecial();
  }
}

void InputManager::initMapper(input_mapping_t kind) {
  switch (kind) {
    case MAPPING_P1:
      this->mapper.prop = SDL_SCANCODE_UP;
      this->mapper.left = SDL_SCANCODE_LEFT;
      this->mapper.right = SDL_SCANCODE_RIGHT;
      this->mapper.fire = SDL_SCANCODE_SPACE;
      this->mapper.spec = SDL_SCANCODE_X;
      break;
    case MAPPING_P2:
      this->mapper.prop = SDL_SCANCODE_W;
      this->mapper.left = SDL_SCANCODE_A;
      this->mapper.right = SDL_SCANCODE_D;
      this->mapper.fire = SDL_SCANCODE_LSHIFT;
      this->mapper.spec = SDL_SCANCODE_LCTRL;
      break;
    default:
      break;
  }
}

InputManager::~InputManager() {
  
}