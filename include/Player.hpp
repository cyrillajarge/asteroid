#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
class Player {
  public:
    int score;
    std::string name;

  public:
    Player();
    Player(std::string name);
    ~Player();
};

#endif