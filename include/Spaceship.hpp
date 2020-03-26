#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Asteroid.hpp"
#include "Particles/LifeParticle.hpp"
#include "Particles/ParticlesManager.hpp"
#include "Rocket.hpp"
#include "SDL2/SDL.h"
#include "Weapon.hpp"
#include "glm/glm.hpp"
#include <iterator>
#include <list>
#include <memory>
#include <vector>

#define VEL_ATTENUATION 0.98f
#define DIR_VECTOR_REGULATION 0.4f

class Spaceship {
public:
  glm::vec2 position;
  double direction_angle;
  glm::vec2 velocity;
  bool boostActive;
  std::unique_ptr<ParticlesManager> pmship;
  int size;
  std::unique_ptr<Weapon> weapon;

public:
  Spaceship(glm::vec2 position, int size);
  ~Spaceship();
  void activateBoost();
  void deactivateBoost();
  void update(double rotation, int width, int height);
  void boost();
  void fireRocket();
  void fireSpecial();
  bool intersectsAsteroid(std::vector<Asteroid *> asteroids);
  void draw(SDL_Renderer *renderer);
  glm::vec2 getDirection();
};

#endif