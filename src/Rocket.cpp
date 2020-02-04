#include "Rocket.hpp"

Rocket::Rocket(glm::vec2 position, glm::vec2 direction) {
  this->position = position;
  this->direction = direction;
}

int Rocket::intersectsAsteroid(std::vector<Asteroid *> asteroids) {
  for (size_t i = 0; i < asteroids.size(); i++) {
    std::vector<glm::vec2> BB = asteroids[i]->BB;
    glm::vec2 asteroid_position = asteroids[i]->center;
    if ((this->position.x < (asteroid_position.x + BB[0].x)) &&
        (this->position.x > (asteroid_position.x + BB[1].x)) &&
        (this->position.y < (asteroid_position.y + BB[2].y)) &&
        (this->position.y > (asteroid_position.y + BB[0].y))) {
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