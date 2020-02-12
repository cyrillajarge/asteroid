#include "Particles/ParticlesManager.hpp"

void ParticlesManager::addParticle(Particle* p){
  this->particles.push_back(p);
}

void ParticlesManager::addLifeParticle(LifeParticle* p){
  this->lifeparticles.push_back(p);
}

void ParticlesManager::updateParticles(){
  for (auto i = this->particles.begin(); i != this->particles.end(); ++i) { 
    (*i)->update(); 
  }
  for (auto i = this->lifeparticles.begin(); i != this->lifeparticles.end(); ++i) { 
    (*i)->update(); 
    if ((*i)->life && (*i)->life < 0) { 
      this->lifeparticles.erase(i); 
      i--; 
    }
  } 
}

void ParticlesManager::drawParticles(SDL_Renderer* renderer){
  for (auto i = this->particles.begin(); i != this->particles.end(); ++i) { 
    (*i)->draw(renderer);
  }
  for (auto i = this->lifeparticles.begin(); i != this->lifeparticles.end(); ++i) { 
    (*i)->draw(renderer);
  } 
}