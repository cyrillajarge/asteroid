#include "Gattling.hpp"
#include "glm/vec2.hpp"
#include <iostream>

Gattling::Gattling(double &angle, glm::vec2 &pos)
    : Weapon(angle, pos) {
  this->fire_rate = GT_ROF;
  this->cooldown = GT_CD * 1000;
  this->rockets.reserve(40);
  this->name = "Gattling";
  this->spec_duration = 0;
}

void Gattling::fire() {
  glm::vec2 rocket_dir = glm::vec2(cos(this->angle), sin(this->angle));
  Rocket *rocket = new Rocket(this->pos + 30.0f * rocket_dir, rocket_dir);
  this->rockets.push_back(rocket);
}

void Gattling::fireSpecial() {
  if (this->cooldown) {
    return;
  }
  this->fire_rate *= 2;
  this->cooldown = GT_CD * 1000;
  this->spec_duration = GT_DUR * 1000;
}

void Gattling::update(int width, int height) {
  auto it = this->rockets.begin();
  while (it != this->rockets.end()) {
    if ((*it)->position.x < 0 || (*it)->position.x > width ||
        (*it)->position.y < 0 || (*it)->position.y > height) {
      it = this->rockets.erase(it);
    } else {
      (*it)->position += ROCKET_VEL * (*it)->direction;
      ++it;
    }
  }
  if (!this->spec_duration) {
    this->fire_rate = GT_ROF;
  }
}

void Gattling::draw(SDL_Renderer *renderer) {
  SDL_Color rocket_color = { 255, 255, 0, 255 };
  if (this->spec_duration) {
    rocket_color.g = 100;
  }
  for (Rocket *r : this->rockets) {
    r->draw(renderer, rocket_color);
  }
}

std::vector<int> Gattling::collided(std::vector<Asteroid *> asteroids) {
  std::vector<int> res;
  auto it = this->rockets.begin();
  while (it != this->rockets.end()) {
    int i = (*it)->intersectsAsteroid(asteroids);
    if (i != -1) {
      it = this->rockets.erase(it);
      res.push_back(i);
    } else {
      ++it;
    }
  }
  return res;
}

void Gattling::debug() {
  Weapon::debug();
  std::cout << this->rockets.size() << " rockets alive." << std::endl;
}

Gattling::~Gattling() { this->rockets.clear(); }