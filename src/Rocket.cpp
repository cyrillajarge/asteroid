#include "Rocket.hpp"

Rocket::Rocket(vec2 position){
  this->position = position;
}

void Rocket::draw(SDL_Renderer* renderer){
  // Set render color to black ( background will be rendered in this color )
  SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

  // Clear winow
  SDL_RenderClear( renderer );

  SDL_Rect r;
  r.x = this->position.x;
  r.y = this->position.y;
  r.w = 5;
  r.h = 5;

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255 );

  SDL_RenderFillRect( renderer, &r );

  // Render the rect to the screen
  SDL_RenderPresent(renderer);
}