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
    int averageray;
    std::vector<glm::vec2> BB;
    int  nrays;
    int level;
    glm::vec2 direction;

  public:
    Asteroid(glm::vec2 position, glm::vec2 direction, int averageray, int nrays, int level);
    ~Asteroid();
    void computeBB();
    void draw(SDL_Renderer* renderer);
    
    /**
     * @brief returns the coordinates of the hitbox points
     * starts from top left and ends at bottom left
     * 
     * @return std::vector<int> 
     */
    // std::vector<int> getHB();
};

#endif