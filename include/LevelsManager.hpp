#ifndef LEVELSMANAGER_H
#define LEVELSMANAGER_H

#include "SDL2/SDL.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>


class LevelsManager{
  public:
    int status;
    std::vector<std::pair<int, float>> config;
    bool message;

    LevelsManager(std::string path);
    std::vector<std::pair<int, float>> readConfigFile(std::string path);
    void nextLevel();
    void resetLevels();
    void drawMessage(SDL_Renderer *renderer, int height, int width);
};

#endif