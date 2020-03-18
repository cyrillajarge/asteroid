#include "Weapon.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

Weapon::Weapon(double &ng, glm::vec2 &p) : angle(ng), pos(p) {}

void Weapon::updateCooldown(int delta) {
  if (this->cooldown >= delta) {
    this->cooldown -= delta;
  } else {
    this->cooldown = 0;
  }
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

Weapon::~Weapon() { std::cout << "Weapon destroyed" << std::endl; }
void Weapon::debug() {
  std::cout << "(angle: " << this->angle << ") "
            << "(pos: " << this->pos.x << ", " << this->pos.y << ")"
            << std::endl;
}