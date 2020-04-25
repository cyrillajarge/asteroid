#include "Player.hpp"
#include <iostream>

Player::Player(input_mapping_t m, glm::vec4 color) {
  this->score = 0;
  this->level = 1;
  this->alive = true;
  this->name = "anonymous";
  this->spaceship = nullptr;
  this->input_manager = std::make_unique<InputManager>(m);
  this->color = color;
  std::cout << "Player created" << std::endl;
}

Player::Player(std::string name) {
  this->score = 0;
  this->level = 1;
  this->name = name;
  this->spaceship = nullptr;
}

void Player::initShip(glm::vec2 position, int size) {
  this->spaceship = std::make_shared<Spaceship>(position, size);
  this->input_manager->attach(this->spaceship);
}

double Player::getDelta() { return this->input_manager->deltaRotation; }

void Player::resetDelta() { this->input_manager->deltaRotation = 0.; }

Player::~Player() {
  std::cout << "Game endend with " << this->score << " points." << std::endl;
}