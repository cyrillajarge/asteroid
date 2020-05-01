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
  /**
   * @brief Construct a new Rocket object
   * 
   * @param position 
   * @param direction 
   */
  Rocket(glm::vec2 position, glm::vec2 direction);

  /**
   * @brief Checks in the rocket collided with an asteroid
   * 
   * @param asteroids vector of asteroids
   * @return index of the collided asteroid in the vector (-1 if no collision)
   */
  int intersectsAsteroid(std::vector<Asteroid *> asteroids);

  /**
   * @brief Draws the rocket with default color
   * 
   * @param renderer 
   */
  void draw(SDL_Renderer *renderer);

  /**
   * @brief Draws the rocket with custom color
   * 
   * @param renderer 
   * @param c 
   */
  void draw(SDL_Renderer *renderer, SDL_Color c);
};

#endif