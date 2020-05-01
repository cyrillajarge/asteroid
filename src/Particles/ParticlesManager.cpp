#include "Particles/ParticlesManager.hpp"

void ParticlesManager::addParticle(Particle* p){
  this->particles.push_back(p);
}

void ParticlesManager::updateParticles(){
  for (auto i = this->particles.begin(); i != this->particles.end(); ++i) {
    LifeParticle* lp = dynamic_cast<LifeParticle *>(*i);
    if(lp != NULL){
      lp->update(); 
      if(lp->life < 0) {
        this->particles.erase(i); 
        i--; 
      }
    }
    else{
      (*i)->update();
    }
  }
}

void ParticlesManager::drawParticles(SDL_Renderer* renderer){
  for (auto i = this->particles.begin(); i != this->particles.end(); ++i) { 
    (*i)->draw(renderer);
  }
}

ParticlesManager::~ParticlesManager() {
  this->particles.clear();
}