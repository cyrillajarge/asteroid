#ifndef ROCKET_H
#define ROCKET_H

#include <iostream>
#include <vector>
#include <cmath>
#include "SDL2/SDL.h"
#include "glm/glm.hpp"

#define ROCKET_VEL 15.0f

using namespace glm;
using namespace std;

class Rocket{
  public:
    vec2 position;
    vec2 direction;

  public:
    Rocket(vec2 position, vec2 direction);
    void draw(SDL_Renderer* renderer);
};

#endif