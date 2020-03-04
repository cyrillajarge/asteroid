#ifndef PARTICLE_H
#define PARTICLE_H

#include "SDL2/SDL.h"
#include "glm/glm.hpp"

#define SPEED_FACTOR 10.0f

class Particle{
  public:
    glm::vec4 color;
    glm::vec2 position;
    glm::vec2 speed;
  
    Particle(glm::vec4 color, glm::vec2 position, glm::vec2 speed): color(color), position(position), speed(speed){}
    void virtual update();
    void draw(SDL_Renderer* renderer);
};


#endif