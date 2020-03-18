#include "Asteroid.hpp"
#include "Random/Alea.hpp"

Asteroid::Asteroid(glm::vec2 position, glm::vec2 direction, int averageray,
                   int nrays, int level) {

  this->center = position;
  this->nrays = nrays;
  this->averageray = averageray;
  this->level = level;

  auto random = alea_generator(-5, 5);

  float random_ray = 0.0;

  for (int i = 0; i < nrays; i++) {
    random_ray = this->averageray + random() % (this->averageray / 2);
    this->rays.push_back(random_ray);
  }
  this->rays.push_back(this->rays[0]);

  this->direction = direction;
}

void Asteroid::draw(SDL_Renderer *renderer) {

  float angle = (2.0f * M_PI) / this->nrays;

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  for (int i = 0; i < this->nrays; i++) {
    SDL_RenderDrawLine(
        renderer, this->center.x + this->rays[i] * cos(i * angle),
        this->center.y + this->rays[i] * sin(i * angle),
        this->center.x + this->rays[i + 1] * cos((i + 1) * angle),
        this->center.y + this->rays[i + 1] * sin((i + 1) * angle));
  }
}

Asteroid::~Asteroid() {}
