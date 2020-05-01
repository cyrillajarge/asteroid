#ifndef ASTEROID_H
#define ASTEROID_H

#include <SDL.h>
#include "glm/glm.hpp"
#include <cmath>
#include <iostream>
#include <iterator>
#include <list>
#include <random>
#include <vector>

class Asteroid {
public:
  glm::vec2 center;
  std::vector<int> rays;
  int averageray;
  std::vector<glm::vec2> BB;
  int nrays;
  int level;
  glm::vec2 direction;

public:
  Asteroid(glm::vec2 position, glm::vec2 direction, int averageray, int nrays,
           int level);
  ~Asteroid();
  void draw(SDL_Renderer *renderer);
};

#endif