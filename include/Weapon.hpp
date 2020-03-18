#ifndef WEAPON_H
#define WEAPON_H
#include "glm/vec2.hpp"
#include "SDL2/SDL.h"
#include "Asteroid.hpp"
#include <vector>
#include <memory>

class Weapon {
  public:
    int cooldown = 10;
    int fire_rate = 10 ;
    double &angle;
    glm::vec2 &pos;
  public:
    Weapon(double &ng, glm::vec2 &p) : angle(ng), pos(p) {}
    void debug();
    // virtual ~Weapon();
    // virtual void fire() = 0;
    // virtual void fireSpecial() = 0;
    // virtual std::vector<int> collided(std::vector<Asteroid *>) = 0;
    // virtual void update(int width, int height) = 0;
    // virtual void draw(SDL_Renderer *renderer) = 0;
};

#endif