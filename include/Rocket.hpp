#ifndef ROCKET_H
#define ROCKET_H

#include <iostream>
#include <vector>
#include <cmath>
#include "SDL2/SDL.h"
#include "glm/glm.hpp"

using namespace glm;
using namespace std;

class Rocket{
  private:
    vec2 position;

  public:
    Rocket(vec2 position);
    void draw(SDL_Renderer* renderer);
};

#endif