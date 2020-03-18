#include "Weapon.hpp"
#include <iostream>

void Weapon::debug() {
  std::cout << this->angle << " " << this->pos.x << std::endl;
}