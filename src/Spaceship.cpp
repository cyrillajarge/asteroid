#include "Spaceship.hpp"
#include <iostream>
#include <cmath>

using namespace std;

Spaceship::Spaceship(vec2 position, SDL_Renderer* renderer){
  this->position = position;
  this->renderer = renderer;
  this->direction_angle = 0.0f;
  this->velocity = vec2(0.0f, 0.0f);
  this->boostActive = false;
}

void Spaceship::activateBoost(){
  this->boostActive = true;
}

void Spaceship::deactivateBoost(){
  this->boostActive = false;
}

void Spaceship::update(double rotation, int width, int height){
  this->direction_angle += rotation;
  if(this->boostActive){
    this->boost();
  }
  this->position += this->velocity;
  if(this->position.x > width){
    this->position.x = 0;
  }
  if(this->position.x < 0){
    this->position.x = width;
  }
  if(this->position.y > height){
    this->position.y = 0;
  }
  if(this->position.y < 0){
    this->position.y = height;
  }
  this->velocity *= VEL_ATTENUATION;

	auto it = this->rockets.begin();
	while (it != this->rockets.end())
	{
		if((*it)->position.x < 0 || (*it)->position.x > width || (*it)->position.y < 0 || (*it)->position.y > height) {
			it = this->rockets.erase(it);
		}
		else {
      (*it)->position += ROCKET_VEL * (*it)->direction;
			++it;
		}
	}
}

void Spaceship::boost(){
  vec2 direction_vector = DIR_VECTOR_REGULATION * vec2(cos(this->direction_angle), sin(this->direction_angle));
  this->velocity += direction_vector;
}

void Spaceship::fireRocket(Rocket* rocket){
  this->rockets.push_back(rocket);
}

void Spaceship::draw(){
  // Set render color to black ( background will be rendered in this color )
  SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

  // Clear winow
  SDL_RenderClear( this->renderer );

  int d = 20;
  vec2 lower_left = vec2(this->position.x + d * cos((2*M_PI/3) + this->direction_angle), this->position.y + d * sin((2*M_PI)/3 + direction_angle));
  vec2 lower_right = vec2(this->position.x + d * cos((4*M_PI/3) + this->direction_angle), this->position.y + d * sin((4*M_PI)/3 + direction_angle));
  vec2 tip = vec2(this->position.x + 2 * d * cos(this->direction_angle), this->position.y + 2 * d * sin(this->direction_angle));

 if(this->boostActive){
    // Propulseur
    SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255 );
    vec2 boost_left = 0.2f * lower_left + 0.8f * lower_right;
    vec2 boost_right = 0.2f * lower_right + 0.8f * lower_left;
    vec2 boost_tip = this->position - 30.0f * vec2(cos(this->direction_angle), sin(this->direction_angle));
    SDL_RenderDrawLine(this->renderer, boost_left.x, boost_left.y, boost_right.x, boost_right.y);
    SDL_RenderDrawLine(this->renderer, boost_left.x, boost_left.y, boost_tip.x, boost_tip.y);
    SDL_RenderDrawLine(this->renderer, boost_right.x, boost_right.y, boost_tip.x, boost_tip.y);
  }

  SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255 );

  SDL_RenderDrawLine(this->renderer, lower_right.x, lower_right.y, tip.x, tip.y);
  SDL_RenderDrawLine(this->renderer, lower_right.x, lower_right.y, lower_left.x, lower_left.y);
  SDL_RenderDrawLine(this->renderer, lower_left.x, lower_left.y, tip.x, tip.y);

  for(Rocket* r: this->rockets){
    r->draw(this->renderer);
  }

  // Render the rect to the screen
  SDL_RenderPresent(this->renderer);
}