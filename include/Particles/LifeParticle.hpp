#ifndef LIFEPARTICLE_HPP
#define LIFEPARTICLE_HPP

#include "Particle.hpp"

class LifeParticle : public Particle{
  public:
    int life;
  
    LifeParticle(glm::vec4 color, glm::vec2 position, glm::vec2 speed, int life): Particle(color, position, speed), life(life){}
    void update();

};

#endif