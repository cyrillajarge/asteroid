#ifndef ASTEROID_H
#define ASTEROID_H

#include <cmath>
#include <random>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include "glm/glm.hpp"
#include "SDL2/SDL.h"

class Asteroid {
  public:
    glm::vec2 center;
    std::vector<int> rays;
    int  nrays;
    glm::vec2 direction;

  public:
    Asteroid(glm::vec2 position, glm::vec2 direction, int nrays);
    ~Asteroid();
    void draw(SDL_Renderer* renderer);
};

#endif