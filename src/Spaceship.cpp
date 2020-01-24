#include "Spaceship.hpp"

using namespace std;

Spaceship::Spaceship(vec2 position, double angle, vec2 direction, SDL_Renderer* renderer){
  this->position = position;
  this->renderer = renderer;
  this->angle = angle;
  this->direction = direction;
}

void Spaceship::draw(){
  // Set render color to red ( background will be rendered in this color )
  SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

  // Clear winow
  SDL_RenderClear( this->renderer );

  // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
  // SDL_Rect r;
  // r.x = this->x_position;
  // r.y = this->y_position;
  // r.w = 10;
  // r.h = 10;

  // Set render color to white ( rect will be rendered in this color )
  SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255 );

  int d = 20;

  SDL_RenderDrawLine(this->renderer, this->position.x + d * cos((4*M_PI/3) + this->angle), this->position.y + d * sin((4*M_PI)/3 + angle), this->position.x + 2 * d * cos(this->angle), this->position.y + 2 * d * sin(this->angle));
  SDL_RenderDrawLine(this->renderer, this->position.x + d * cos((4*M_PI/3) + this->angle), this->position.y + d * sin((4*M_PI)/3 + angle), this->position.x + d * cos((2*M_PI/3) + this->angle), this->position.y + d * sin((2*M_PI)/3 + angle));
  SDL_RenderDrawLine(this->renderer, this->position.x + d * cos((2*M_PI/3) + this->angle), this->position.y + d * sin((2*M_PI)/3 + angle), this->position.x + 2 * d * cos(this->angle), this->position.y + 2 * d * sin(this->angle));

  // Render rect
  // SDL_RenderFillRect( this->renderer, &r );

  // Render the rect to the screen
  SDL_RenderPresent(this->renderer);
}

void Spaceship::accelerate(double speed){
  cout << "direction: "<< this->direction.x << " , "<< this->direction.y << endl;
  cout << "position: "<< this->position.x << " , "<< this->position.y << endl;
  this->position = vec2(this->position.x + this->direction.x, this->position.y + this->direction.y);
}

void Spaceship::setDirection(double angle){
  this->angle = angle;
  this->direction = vec2(cos(angle), sin(angle));
}
