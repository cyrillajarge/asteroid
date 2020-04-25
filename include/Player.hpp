#ifndef PLAYER_H
#define PLAYER_H

#include "InputManager.hpp"
#include "Spaceship.hpp"
#include "glm/vec2.hpp"
#include "LevelsManager.hpp"
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
   * @brief Level that the player reached
   * 
   */
  int level;

  /**
   * @brief Player is alive
   * 
   */
  bool alive;

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

  /**
   * @brief Input Manager that parses user inputs during game
   *
   */
  std::unique_ptr<InputManager> input_manager;

public:
  Player(input_mapping_t m);
  Player(std::string name);
  ~Player();
  /**
   * @brief Instanciates a spaceship and attaches it to the input manager
   *
   * @param position
   * @param size
   */
  void initShip(glm::vec2 position, int size);

  /**
   * @brief returns the delta rotation stored in the input manager
   *
   * @return double
   */
  double getDelta();

  /**
   * @brief resets the delta rotation
   *
   */
  void resetDelta();
};

#endif