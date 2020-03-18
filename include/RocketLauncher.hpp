#ifndef ROCKETLAUNCHER_H
#define ROCKETLAUNCHER_H
#include "Weapon.hpp"
#include "Rocket.hpp"
#include <vector>

#define RL_ROF 5
#define RL_CD 15

class RocketLauncher : public Weapon {
  public:
    void fire();
    void fireSpecial();
    void update(int width, int height);
    void draw(SDL_Renderer *renderer);
    std::vector<int> collided(std::vector<Asteroid *>);
    std::vector<Rocket*> rockets;

  public:
    RocketLauncher(double &angle, glm::vec2 &pos);
    ~RocketLauncher();
    void debug();

};

#endif