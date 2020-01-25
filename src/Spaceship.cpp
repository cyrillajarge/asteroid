#include "Spaceship.hpp"

using namespace std;

Spaceship::Spaceship(vec2 position, SDL_Renderer* renderer){
  this->position = position;
  this->renderer = renderer;
  this->angle = 0.0f;
  this->direction = vec2(1.0f,0.0f);
}

void Spaceship::draw(bool accelerationmarker){
  // Set render color to black ( background will be rendered in this color )
  SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

  // Clear winow
  SDL_RenderClear( this->renderer );

  // Set render color to white ( rect will be rendered in this color )
  // SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255 );

  int d = 20;
  vec2 lower_left = vec2(this->position.x + d * cos((2*M_PI/3) + this->angle), this->position.y + d * sin((2*M_PI)/3 + angle));
  vec2 lower_right = vec2(this->position.x + d * cos((4*M_PI/3) + this->angle), this->position.y + d * sin((4*M_PI)/3 + angle));
  vec2 tip = vec2(this->position.x + 2 * d * cos(this->angle), this->position.y + 2 * d * sin(this->angle));
 
 if(accelerationmarker){
    // Propulseur
    SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255 );
    vec2 boost_left = 0.2f * lower_left + 0.8f * lower_right;
    vec2 boost_right = 0.2f * lower_right + 0.8f * lower_left;
    vec2 boost_tip = this->position - 30.0f * vec2(cos(this->angle), sin(this->angle));
    SDL_RenderDrawLine(this->renderer, boost_left.x, boost_left.y, boost_right.x, boost_right.y);
    SDL_RenderDrawLine(this->renderer, boost_left.x, boost_left.y, boost_tip.x, boost_tip.y);
    SDL_RenderDrawLine(this->renderer, boost_right.x, boost_right.y, boost_tip.x, boost_tip.y);
  }

  SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255 );

  SDL_RenderDrawLine(this->renderer, lower_right.x, lower_right.y, tip.x, tip.y);
  SDL_RenderDrawLine(this->renderer, lower_right.x, lower_right.y, lower_left.x, lower_left.y);
  SDL_RenderDrawLine(this->renderer, lower_left.x, lower_left.y, tip.x, tip.y);

  // Render the rect to the screen
  SDL_RenderPresent(this->renderer);
}

void Spaceship::accelerate(double acceleration){
  // cout << "direction: "<< this->direction.x << " , "<< this->direction.y << endl;
  // cout << "position: "<< this->position.x << " , "<< this->position.y << endl;
  
  this->position = vec2(this->position.x + acceleration * this->direction.x, this->position.y + acceleration * this->direction.y);
}

void Spaceship::rotate(double angle){
  this->angle = (M_PI * angle) / 180.0f;
  this->draw(false);
}

void Spaceship::setDirection(double angle){
  this->angle = (M_PI * angle)/180.0f;
  this->direction = vec2(cos(angle), sin(angle));
}
