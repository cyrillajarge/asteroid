#include "Weapon.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

int updateTime(int cur, int delta) {
  if (cur > delta) {
    return cur - delta;
  }
  return 0;
}

Weapon::Weapon(double &ng, glm::vec2 &p) : angle(ng), pos(p) {}

void Weapon::updateCooldown(int delta) {
  this->cooldown = updateTime(this->cooldown, delta);
}

void Weapon::updateDuration(int delta) {
  this->spec_duration = updateTime(this->spec_duration, delta);
}

std::string Weapon::getCDStr() {
  double cd = static_cast<double>(this->cooldown);
  if (this->cooldown) {
    std::ostringstream cd_stream;
    cd_stream << std::fixed << std::setprecision(1) << (cd / 1000);
    return cd_stream.str();
  }
  return "Ready";
}

Weapon::~Weapon() {}
void Weapon::debug() {
  std::cout << "(angle: " << this->angle << ") "
            << "(pos: " << this->pos.x << ", " << this->pos.y << ")"
            << std::endl;
}