#ifndef PARTICLEMANAGER_HPP
#define PARTICLEMANAGER_HPP

#include "Particle.hpp"
#include "LifeParticle.hpp"

#include <vector>
#include <iostream>

class ParticlesManager{
  public:
    /**
    * @brief All particles
    */
    std::vector<Particle*> particles;

    ParticlesManager(){}
    ~ParticlesManager();

    /**
    * @brief Adds a particle to the vector of particles
    *
    * @param p
    */
    void addParticle(Particle* p);
    
    /**
    * @brief Updates the particles depending on their types (regular particle or life particle)
    */
    void updateParticles();
    
    /**
    * @brief Draw all the particles
    *
    * @param renderer
    */
    void drawParticles(SDL_Renderer* renderer);
};

#endif