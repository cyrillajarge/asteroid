#ifndef GATTLING_H
#define GATTLING_H
#include "Rocket.hpp"
#include "Weapon.hpp"
#include <vector>

#define GT_ROF 7
#define GT_CD 15
#define GT_DUR 5

class Gattling : public Weapon {
public:
  /**
   * @brief Rockets fired and "alive"
   *
   */
  std::vector<Rocket *> rockets;
  
  Gattling(double &angle, glm::vec2 &pos);
  ~Gattling();
  
  void fire();
  void fireSpecial();
  void update(int width, int height);
  void draw(SDL_Renderer *renderer);
  std::vector<int> collided(std::vector<Asteroid *>);
  void debug();
};

#endif