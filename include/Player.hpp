#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
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

public:
  Player();
  Player(std::string name);
  ~Player();
};

#endif