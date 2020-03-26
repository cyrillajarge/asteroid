#include "Player.hpp"

Player::Player() {
  this->score = 0;
  this->name = "anonymous";
  this->spaceship = nullptr;
}

Player::Player(std::string name) {
  this->score = 0;
  this->name = name;
  this->spaceship = nullptr;
}

Player::~Player() {
  std::cout << "Game endend with " << this->score << " points." << std::endl;
}