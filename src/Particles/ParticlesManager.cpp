#include "Particles/ParticlesManager.hpp"

void ParticlesManager::addParticle(Particle* p){
  this->particles.push_back(p);
}

void ParticlesManager::updateParticles(){
  std::vector<Particle*>::const_iterator iterator;
  for (auto i = this->particles.begin(); i != this->particles.end(); ++i) { 
    if(dynamic_cast<LifeParticle *>(*i) != NULL){
      dynamic_cast<LifeParticle *>(*i)->update(); 
      if(dynamic_cast<LifeParticle *>(*i)->life < 0) {
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