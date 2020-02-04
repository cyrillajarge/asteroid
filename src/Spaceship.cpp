#include "Spaceship.hpp"
#include <iostream>
#include <cmath>
#include "Blade.hpp"

Spaceship::Spaceship(Player *p, glm::vec2 position, int size){
  this->position = position;
  this->player = p;
  this->size = size;
  this->direction_angle = 0.0f;
  this->velocity = glm::vec2(0.0f, 0.0f);
  this->boostActive = false;
}

glm::vec2 Spaceship::getDirection() {
  return glm::vec2(cos(this->direction_angle), sin(this->direction_angle));
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
  glm::vec2 direction_vector = DIR_VECTOR_REGULATION * glm::vec2(cos(this->direction_angle), sin(this->direction_angle));
  this->velocity += direction_vector;
}

void Spaceship::fireRocket(Rocket* rocket){
  this->rockets.push_back(rocket);
}

bool Spaceship::intersectsAsteroid(std::vector<Asteroid*> asteroids){
  glm::vec2 lower_left = glm::vec2(this->position.x + this->size * cos((2*M_PI/3) + this->direction_angle), this->position.y + this->size * sin((2*M_PI)/3 + direction_angle));
  glm::vec2 lower_right = glm::vec2(this->position.x + this->size * cos((4*M_PI/3) + this->direction_angle), this->position.y + this->size * sin((4*M_PI)/3 + direction_angle));
  glm::vec2 tip = glm::vec2(this->position.x + 2 * this->size * cos(this->direction_angle), this->position.y + 2 * this->size * sin(this->direction_angle));

  for(size_t i=0; i < asteroids.size() ;i++){
    std::vector<glm::vec2> BB = asteroids[i]->BB;
    glm::vec2 asteroid_position = asteroids[i]->center;
    if((lower_left.x < (asteroid_position.x + BB[0].x)) && (lower_left.x > (asteroid_position.x + BB[1].x)) && (lower_left.y < (asteroid_position.y + BB[2].y)) && (lower_left.y >(asteroid_position.y + BB[0].y))){
      return true;
    }
    if((lower_right.x < (asteroid_position.x + BB[0].x)) && (lower_right.x > (asteroid_position.x + BB[1].x)) && (lower_right.y < (asteroid_position.y + BB[2].y)) && (lower_right.y >(asteroid_position.y + BB[0].y))){
      return true;
    }
    if((tip.x < (asteroid_position.x + BB[0].x)) && (tip.x > (asteroid_position.x + BB[1].x)) && (tip.y < (asteroid_position.y + BB[2].y)) && (tip.y >(asteroid_position.y + BB[0].y))){
      return true;
    }
  }
  return false;
}


void Spaceship::draw(SDL_Renderer* renderer){

  int d = this->size;
  glm::vec2 lower_left = glm::vec2(this->position.x + d * cos((2*M_PI/3) + this->direction_angle), this->position.y + d * sin((2*M_PI)/3 + direction_angle));
  glm::vec2 lower_right = glm::vec2(this->position.x + d * cos((4*M_PI/3) + this->direction_angle), this->position.y + d * sin((4*M_PI)/3 + direction_angle));
  glm::vec2 tip = glm::vec2(this->position.x + 2 * d * cos(this->direction_angle), this->position.y + 2 * d * sin(this->direction_angle));

 if(this->boostActive){
    // Propulseur
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255 );
    glm::vec2 boost_left = 0.2f * lower_left + 0.8f * lower_right;
    glm::vec2 boost_right = 0.2f * lower_right + 0.8f * lower_left;
    glm::vec2 boost_tip = this->position - 30.0f * glm::vec2(cos(this->direction_angle), sin(this->direction_angle));
    SDL_RenderDrawLine(renderer, boost_left.x, boost_left.y, boost_right.x, boost_right.y);
    SDL_RenderDrawLine(renderer, boost_left.x, boost_left.y, boost_tip.x, boost_tip.y);
    SDL_RenderDrawLine(renderer, boost_right.x, boost_right.y, boost_tip.x, boost_tip.y);
  }

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255 );

  SDL_RenderDrawLine(renderer, lower_right.x, lower_right.y, tip.x, tip.y);
  SDL_RenderDrawLine(renderer, lower_right.x, lower_right.y, lower_left.x, lower_left.y);
  SDL_RenderDrawLine(renderer, lower_left.x, lower_left.y, tip.x, tip.y);

  for(Rocket* r: this->rockets){
    r->draw(renderer);
  }
  Blade b = Blade(tip, this->getDirection());
  b.draw(renderer);
}