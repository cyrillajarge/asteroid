#ifndef ASTEROID_H
#define ASTEROID_H

#include "SDL2/SDL.h"
#include "glm/glm.hpp"
#include <cmath>
#include <iostream>
#include <iterator>
#include <list>
#include <random>
#include <vector>

class Asteroid {
public:
  /**
  * @brief Position of the center of the asteroid
  */
  glm::vec2 center;
  
  /**
  * @brief Defines the rays used to generate the polygon representing the asteroid
  * 
  * @param rays
  */
  std::vector<int> rays;
  
  /**
  * @brief Defines the average length of a ray
  * Used to compute the bounding circle for collisions
  */
  int averageray;
  
  /**
  * @brief Number of rays(sides) of the polygon
  */
  int nrays;
  
  /**
  * @brief Current asteroid level (3 in total)
  */
  int level;
  
  /**
  * @brief Speed vector of the asteroid
  */
  glm::vec2 direction;

  Asteroid(glm::vec2 position, glm::vec2 direction, int averageray, int nrays,
           int level);
  ~Asteroid();

  /**
  * @brief Draws the asteroid
  *
  * @param renderer
  */
  void draw(SDL_Renderer *renderer);
};

#endif