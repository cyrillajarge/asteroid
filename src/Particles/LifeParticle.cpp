#include "Particles/LifeParticle.hpp"

void LifeParticle::update(){
  this->position += SPEED_FACTOR * this->speed;
  this->life--;
}