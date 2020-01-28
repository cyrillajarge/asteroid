#ifndef ROCKET_H
#define ROCKET_H

#include <iostream>
#include <vector>
#include <cmath>
#include "SDL2/SDL.h"
#include "glm/glm.hpp"

#define ROCKET_VEL 15.0f

class Rocket{
  public:
    glm::vec2 position;
    glm::vec2 direction;

  public:
    Rocket(glm::vec2 position, glm::vec2 direction);
    void draw(SDL_Renderer* renderer);
};

#endif