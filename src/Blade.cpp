#include "Blade.hpp"

Blade::Blade(glm::vec2 position, glm::vec2 direction) {
  this->position = position;
  this->direction = direction;
  this->size = 100;
}

int Blade::intersectsAsteroid(std::vector<Asteroid *> asteroids) {
  // for (size_t i = 0; i < asteroids.size(); i++) {
  //   std::vector<glm::vec2> BB = asteroids[i]->BB;
  //   glm::vec2 asteroid_position = asteroids[i]->center;
  //   if ((this->position.x < (asteroid_position.x + BB[0].x)) &&
  //       (this->position.x > (asteroid_position.x + BB[1].x)) &&
  //       (this->position.y < (asteroid_position.y + BB[2].y)) &&
  //       (this->position.y > (asteroid_position.y + BB[0].y))) {
  //     return i;
  //   }
  // }
  SDL_Rect r;
  int x1, x2, y1, y2;
  for (Asteroid *ast : asteroids) {
    r.x = ast->BB[0].x;
    r.w = ast->BB[1].x;
    r.w = ast->BB[0].y;
    r.h = ast->BB[1].y;

    x1 = this->position.x;
    x2 = this->position.x + this->size * this->direction.x;
    y1 = this->position.y;
    y2 = this->position.y + this->size * this->direction.y;
    if (SDL_IntersectRectAndLine(&r, &x1, &y1, &x2, &y2)) {
      return 1;
    }
  }
  return -1;
}

void Blade::draw(SDL_Renderer *renderer) {

  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

  SDL_RenderDrawLine(renderer, this->position.x, this->position.y,
                     this->position.x + this->size * this->direction.x,
                     this->position.y + this->size * this->direction.y);
}