#include "Rocket.hpp"

Rocket::Rocket(glm::vec2 position, glm::vec2 direction) {
  this->position = position;
  this->direction = direction;
}

int Rocket::intersectsAsteroid(std::vector<Asteroid *> asteroids) {
  for (size_t i = 0; i < asteroids.size(); i++) {
    // disk equation
    int rocketxpos = this->position.x + 2;
    int rocketypos = this->position.y + 2;
    int asterxcenter = asteroids[i]->center.x;
    int asterycenter = asteroids[i]->center.y;
    int averageray = asteroids[i]->averageray;
    if (pow(rocketxpos - asterxcenter, 2.0) +
            pow(rocketypos - asterycenter, 2.0) <=
        pow(averageray, 2.0)) {
      return i;
    }
  }
  return -1;
}

void Rocket::draw(SDL_Renderer *renderer) {

  SDL_Rect r;
  r.x = this->position.x;
  r.y = this->position.y;
  r.w = 5;
  r.h = 5;

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

  SDL_RenderFillRect(renderer, &r);
}

void Rocket::draw(SDL_Renderer *renderer, SDL_Color c) {

  SDL_Rect r;
  r.x = this->position.x;
  r.y = this->position.y;
  r.w = 5;
  r.h = 5;

  SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);

  SDL_RenderFillRect(renderer, &r);
}