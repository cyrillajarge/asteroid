#include "RocketLauncher.hpp"
#include "glm/vec2.hpp"
#include <iostream>

RocketLauncher::RocketLauncher(double &angle, glm::vec2 &pos)
    : Weapon(angle, pos) {
  this->fire_rate = RL_ROF;
  this->cooldown = RL_CD * 1000;
  this->rockets.reserve(20);
  this->name = "Rocket Launcher";
}

void RocketLauncher::fire() {
  glm::vec2 rocket_dir = glm::vec2(cos(this->angle), sin(this->angle));
  Rocket *rocket = new Rocket(this->pos + 30.0f * rocket_dir, rocket_dir);
  this->rockets.push_back(rocket);
}

void RocketLauncher::fireSpecial() {
  if (this->cooldown) {
    return;
  }
  Rocket *rocket;
  glm::vec2 rocket_dir;
  for (double i = 0.; i < 2 * M_PI; i += M_PI / 6.) {
    rocket_dir = glm::vec2(cos(i), sin(i));
    rocket = new Rocket(this->pos + 30.0f * rocket_dir, rocket_dir);
    this->rockets.push_back(rocket);
  }
  this->cooldown = RL_CD * 1000;
}

void RocketLauncher::update(int width, int height) {
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
}

void RocketLauncher::draw(SDL_Renderer *renderer) {
  for (Rocket *r : this->rockets) {
    r->draw(renderer);
  }
}

std::vector<int> RocketLauncher::collided(std::vector<Asteroid *> asteroids) {
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

void RocketLauncher::debug() {
  Weapon::debug();
  std::cout << this->rockets.size() << " rockets alive." << std::endl;
}

RocketLauncher::~RocketLauncher() { this->rockets.clear(); }