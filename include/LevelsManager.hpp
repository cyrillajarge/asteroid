#ifndef LEVELSMANAGER_H
#define LEVELSMANAGER_H

#include "SDL2/SDL.h"
#include <iostream>


class LevelsManager{
  public:
    int status;
    int nb_asteroids;
    float speed;
    bool message;

    LevelsManager();
    void nextLevel();
    void resetLevels();
    void drawMessage(SDL_Renderer *renderer, int height, int width);
};

#endif