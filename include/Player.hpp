#ifndef PLAYER_H
#define PLAYER_H

#include "Spaceship.hpp"
#include "InputManager.hpp"
#include "glm/vec2.hpp"
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
  std::shared_ptr<Spaceship> spaceship;
  std::unique_ptr<InputManager> input_manager;

public:
  Player();
  Player(std::string name);
  ~Player();
  void initShip(glm::vec2 position, int size);
  double getDelta();
  void resetDelta();
};

#endif