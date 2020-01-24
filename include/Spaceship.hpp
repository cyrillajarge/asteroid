#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "SDL2/SDL.h"
#include <iostream>
#include <vector>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

class Spaceship{
  public:
    vec2 position;
    double angle;
    vec2 direction;
    SDL_Renderer* renderer;

  public:
    Spaceship(vec2 position, double angle, vec2 direction, SDL_Renderer* renderer);
    void draw();
    void accelerate(double speed);
    void setDirection(double angle);
};

#endif