#ifndef ASTEROID_H
#define ASTEROID_H

#include "glm/glm.hpp"

using namespace glm;

class Asteroid {
  private:
    vec2 position;
  public:
    Asteroid(int xpos, int ypos);
    ~Asteroid();
};

#endif