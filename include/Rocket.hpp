#ifndef ROCKET_H
#define ROCKET_H

#include "Asteroid.hpp"
#include "SDL2/SDL.h"
#include "glm/glm.hpp"
#include <cmath>
#include <iostream>
#include <vector>

#define ROCKET_VEL 15.0f

class Rocket {
public:
  glm::vec2 position;
  glm::vec2 direction;

public:
  Rocket(glm::vec2 position, glm::vec2 direction);
  int intersectsAsteroid(std::vector<Asteroid *> asteroids);
  void draw(SDL_Renderer *renderer);
  void draw(SDL_Renderer *renderer, SDL_Color c);
};

#endif