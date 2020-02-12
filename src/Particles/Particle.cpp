#include "Particles/Particle.hpp"


void Particle::update(){
  this->position += SPEED_FACTOR * this->speed;
}

void Particle::draw(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, this->color.x,this->color.y,this->color.z,this->color.w);
	SDL_RenderDrawPoint(renderer,this->position.x,this->position.y);
}