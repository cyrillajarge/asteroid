#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <fstream>
#include <iostream>
#include <memory>
#include "Menu.hpp"

class Scoreboard {
  public:
    std::string path;
    std::vector<std::pair<std::string, int>> scores;

  public:
    Scoreboard();
    void saveScore(std::string name, int score);
    void updateMenu(const std::unique_ptr<Menu>& m, int width);
    void sort();

  private:
    void initScores();
};

#endif