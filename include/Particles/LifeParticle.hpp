#ifndef LIFEPARTICLE_HPP
#define LIFEPARTICLE_HPP

#include "Particle.hpp"

class LifeParticle : public Particle{
  public:
    /**
    * @brief Represets lifetime of the particle
    */
    int life;
  
  public:
    
    LifeParticle(glm::vec4 color, glm::vec2 position, glm::vec2 speed, int life): Particle(color, position, speed), life(life){}
    
    /**
    * @brief Updates life particle
    */
    void update();

};

#endif