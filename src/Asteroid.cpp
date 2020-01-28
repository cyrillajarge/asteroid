#include "Asteroid.hpp"

Asteroid::Asteroid(glm::vec2 position, glm::vec2 direction, int nrays){
  
  this->center = position;
  this->nrays = nrays;
  
  float random_ray;

  for(int i=0;i<nrays;i++){
    random_ray =  30.0f + std::rand() % 20;
    this->rays.push_back(random_ray);
  }
  this->rays.push_back(this->rays[0]);

  this->direction = direction;
}

void Asteroid::draw(SDL_Renderer* renderer){
  
  float angle = (2.0f * M_PI) / this->nrays;
  // std::cout << this->nrays << std::endl;

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255 );

  for(int i=0; i<this->nrays;i++){
    SDL_RenderDrawLine(renderer, this->center.x + this->rays[i] * cos(i * angle), this->center.y + this->rays[i] * sin(i * angle) ,this->center.x + this->rays[i+1] * cos((i+1) * angle), this->center.y + this->rays[i+1] * sin((i+1) * angle));
  }

}

Asteroid::~Asteroid() {

}
