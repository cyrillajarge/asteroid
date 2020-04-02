#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <fstream>
#include <iostream>
#include <unordered_map>
#include "SDL2/SDL.h"


class Scoreboard {
  public:
    std::string path;
    std::unordered_map<std::string,int> scores;

  public:
    Scoreboard();
    void saveScore(std::string name, int score);
    void draw();

  private:
    void initScores();
};

#endif