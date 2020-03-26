#ifndef PLAYER_H
#define PLAYER_H

#include "Spaceship.hpp"
#include <iostream>
#include <memory>
class Player {
public:
  /**
   * @brief Player score
   *
   */
  int score;

  /**
   * @brief Player name
   *
   */
  std::string name;

  /**
   * @brief Spaceship
   * 
   */
  std::unique_ptr<Spaceship> spaceship;

public:
  Player();
  Player(std::string name);
  ~Player();
};

#endif