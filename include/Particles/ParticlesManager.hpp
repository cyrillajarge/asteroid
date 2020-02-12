#ifndef PARTICLEMANAGER_HPP
#define PARTICLEMANAGER_HPP

#include "Particles/LifeParticle.hpp"

#include <vector>

class ParticlesManager{
  public:
    std::vector<Particle*> particles;
    std::vector<LifeParticle*> lifeparticles;

    ParticlesManager(){}
    void addParticle(Particle* p);
    void addLifeParticle(LifeParticle* lp);
    void updateParticles();
    void drawParticles(SDL_Renderer* renderer);
};

#endif