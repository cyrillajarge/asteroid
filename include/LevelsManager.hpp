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
    /**
    * @brief Current level
    */
    int status;
    
    /**
    * @brief Contains config for first levels
    * Data retrived from a configuration file located in config/levels.txt
    */
    std::vector<std::pair<int, float>> config;
    
    /**
    * @brief Tells if level message should be displayed or not
    */
    bool message;

    LevelsManager(std::string path);
    
    /**
    * @brief Reads confguration file and puts data in config attribute
    *
    * @param path
    */
    std::vector<std::pair<int, float>> readConfigFile(std::string path);
    
    /**
    * @brief Changes level status
    * If no more levels are available it creates a new level
    */
    void nextLevel();
    
    /**
    * @brief Resets attributes at default except for config
    */
    void resetLevels();
    
    /**
    * @brief Draws level message
    */
    void drawMessage(SDL_Renderer *renderer, int height, int width);
};

#endif