#include "Blade.hpp"

Blade::Blade(glm::vec2 position, glm::vec2 direction) {
  this->position = position;
  this->direction = direction;
  this->size = 200;
}

int Blade::intersectsAsteroid(std::vector<Asteroid *> asteroids) {
  SDL_Rect r;
  int x1, x2, y1, y2;
  for (size_t i = 0; i < asteroids.size(); i++) {
    std::vector<int> hitbox = asteroids[i]->getHB();
    r.x = hitbox[0];
    r.y = hitbox[3];
    r.w = hitbox[1] - hitbox[0];
    r.h = hitbox[3] - hitbox[0];

    x1 = this->position.x;
    x2 = this->position.x + this->size * this->direction.x;
    y1 = this->position.y;
    y2 = this->position.y + this->size * this->direction.y;
    if (SDL_IntersectRectAndLine(&r, &x1, &y1, &x2, &y2)) {
      return i;
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