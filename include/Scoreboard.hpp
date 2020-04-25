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
    /**
     * @brief Saves the player/team score in the score file
     * 
     * @param name 
     * @param score 
     */
    void saveScore(std::string name, int score);
    /**
     * @brief Update the scoreboard menu with current informations
     * 
     * @param m 
     * @param width 
     */
    void updateMenu(const std::unique_ptr<Menu>& m, int width);
    /**
     * @brief Sort scores
     * 
     */
    void sort();

  private:
    void initScores();
};

#endif