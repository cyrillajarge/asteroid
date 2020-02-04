#include "Player.hpp"


Player::Player() {
  this->score = 0;
  this->name = "anonymous";
}

Player::Player(std::string name) {
  this->score = 0;
  this->name = name;
}

Player::~Player() {
  std::cout << "Game endend with " << this->score << " points." << std::endl;
}