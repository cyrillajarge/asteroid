#include "Asteroid.hpp"

Asteroid::Asteroid(vec2 position, vec2 direction, int averageray, int nrays){
  
  this->center = position;
  this->nrays = nrays;
  this->averageray = averageray;
  
  float random_ray;

  for(int i=0;i<nrays;i++){
    random_ray =  (this->averageray + rand() % 20) - 10;
    this->rays.push_back(random_ray);
  }
  this->rays.push_back(this->rays[0]);

  this->computeBB();

  this->direction = direction;
}

void Asteroid::computeBB(){
  int rayoffset = this->averageray - (this->averageray / 4.0f);
  vec2 topright = vec2(rayoffset);
  vec2 topleft = vec2(-rayoffset,rayoffset);
  vec2 bottomright = vec2(rayoffset, -rayoffset);
  vec2 bottomleft = vec2(-rayoffset, -rayoffset);

  this->BB.push_back(topright);
  this->BB.push_back(topleft);
  this->BB.push_back(bottomleft);
  this->BB.push_back(bottomright);
  this->BB.push_back(topright);
}

void Asteroid::draw(SDL_Renderer* renderer){
  
  float angle = (2.0f * M_PI) / this->nrays;
  // std::cout << this->nrays << std::endl;

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255 );

  for(int i=0; i<this->nrays;i++){
    SDL_RenderDrawLine(renderer, this->center.x + this->rays[i] * cos(i * angle), this->center.y + this->rays[i] * sin(i * angle) ,this->center.x + this->rays[i+1] * cos((i+1) * angle), this->center.y + this->rays[i+1] * sin((i+1) * angle));
  }

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255 );
  for(int i=0;i<this->BB.size()-1;i++){
    SDL_RenderDrawLine(renderer, this->center.x + this->BB[i].x, this->center.y + this->BB[i].y, this->center.x + this->BB[i+1].x, this->center.y + this->BB[i+1].y);
  }

}

Asteroid::~Asteroid() {

}
