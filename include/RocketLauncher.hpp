#ifndef ROCKETLAUNCHER_H
#define ROCKETLAUNCHER_H
#include "Rocket.hpp"
#include "Weapon.hpp"
#include <vector>

#define RL_ROF 3
#define RL_CD 15

class RocketLauncher : public Weapon {
public:
  /**
   * @brief Rockets fired and "alive"
   *
   */
  std::vector<Rocket *> rockets;
  
  RocketLauncher(double &angle, glm::vec2 &pos);
  ~RocketLauncher();
  void fire();
  void fireSpecial();
  void update(int width, int height);
  void draw(SDL_Renderer *renderer);
  std::vector<int> collided(std::vector<Asteroid *>);
  void debug();
};

#endif