#include "Rocket.hpp"

Rocket::Rocket(glm::vec2 position, glm::vec2 direction){
  this->position = position;
  this->direction = direction;
}

void Rocket::draw(SDL_Renderer* renderer){

  SDL_Rect r;
  r.x = this->position.x;
  r.y = this->position.y;
  r.w = 5;
  r.h = 5;

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255 );

  SDL_RenderFillRect( renderer, &r );
}