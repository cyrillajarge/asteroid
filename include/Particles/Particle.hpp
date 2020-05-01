#ifndef PARTICLE_H
#define PARTICLE_H

#include "SDL2/SDL.h"
#include "glm/glm.hpp"

#define SPEED_FACTOR 10.0f

class Particle{
  public:
    /**
    * @brief Particle color
    */
    glm::vec4 color;

    /**
    * @brief Particle position
    */
    glm::vec2 position;

    /**
    * @brief Particle speed
    */
    glm::vec2 speed;
  
  public:

    Particle(glm::vec4 color, glm::vec2 position, glm::vec2 speed): color(color), position(position), speed(speed){}
    
    /**
    * @brief Updates particle
    */
    void virtual update() = 0;
    
    /**
    * @brief Draws particle
    *
    * @param renderer
    */
    void draw(SDL_Renderer* renderer);
};


#endif