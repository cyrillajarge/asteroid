#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Asteroid.hpp"
#include "Particles/LifeParticle.hpp"
#include "Particles/ParticlesManager.hpp"
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
  /**
   * @brief Spaceship position.
   * 
   */
  glm::vec2 position;

  /**
   * @brief Angle (in radians) to which the spacecraft is directed
   * 
   */
  double direction_angle;

  /**
   * @brief 
   * 
   */
  glm::vec2 velocity;

  /**
   * @brief Boolean that indicates if the spaceship is accelerating or not.
   * 
   */
  bool boostActive;

  /**
   * @brief Particle manager for booster.
   * 
   */
  std::unique_ptr<ParticlesManager> pmship;

  /**
   * @brief Size of the spaceship.
   * 
   */
  int size;

  /**
   * @brief Weapon.
   * 
   */
  std::unique_ptr<Weapon> weapon;
  
  /**
   * @brief Boolean that tells if the spaceship is invicible.
   * 
   */
  bool invincible;

  Spaceship(glm::vec2 position, int size);
  ~Spaceship();

  /**
   * @brief Activates boost.
   * 
   */
  void activateBoost();

  /**
   * @brief Deactivates boost.
   * 
   */
  void deactivateBoost();

  /**
   * @brief Updates ship(position and weapons).
   * 
   * @param rotation
   * @param width
   * @param height
   */
  void update(double rotation, int width, int height);

  /**
   * @brief Makes the ship accelerate.
   * 
   */
  void boost();

  /**
   * @brief Checks intersections with asteroids.
   * 
   * @param asteroids
   * 
   * @return bool
   */
  bool intersectsAsteroid(std::vector<Asteroid *> asteroids);

  /**
   * @brief Draws the spaceship and everything associated to it(booster, particles, weapon).
   * 
   * @param renderer
   */
  void draw(SDL_Renderer *renderer, glm::vec4 color);

  /**
   * @brief Computes the direction vector.
   * 
   * @return glm::vec2
   */
  glm::vec2 getDirection();
};

#endif