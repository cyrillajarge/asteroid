#ifndef PARTICLEMANAGER_HPP
#define PARTICLEMANAGER_HPP

#include "Particle.hpp"
#include "LifeParticle.hpp"

#include <vector>
#include <iostream>

class ParticlesManager{
  public:
    std::vector<Particle*> particles;

    ParticlesManager(){}
    void addParticle(Particle* p);
    void updateParticles();
    void drawParticles(SDL_Renderer* renderer);
};

#endif