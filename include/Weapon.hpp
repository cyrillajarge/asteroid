#ifndef WEAPON_H
#define WEAPON_H
#include "Asteroid.hpp"
#include "SDL2/SDL.h"
#include "glm/vec2.hpp"
#include <memory>
#include <string>
#include <vector>

class Weapon {
public:
  /**
   * @brief Weapon name
   * 
   */
  std::string name;

  /**
   * @brief Special action cooldown in milliseconds
   *
   */
  int cooldown;

  /**
   * @brief Shots per second
   *
   */
  int fire_rate;

  /**
   * @brief Duration of special effect (might be unused).
   * 
   */
  int spec_duration;

  /**
   * @brief Angle, must be a reference to the object that holds it (i.e:
   * Spaceship)
   *
   */
  double &angle;

  /**
   * @brief Position, must be a reference to the object that holds it (i.e:
   * Spaceship)
   *
   */
  glm::vec2 &pos;

public:
  Weapon(double &ng, glm::vec2 &p);
  /**
   * @brief Prints angle and position in stdout.
   *
   */
  void debug();

  /**
   * @brief Updates the cooldown based on the time elapsed
   *
   * @param delta int (time elapsed)
   */
  void updateCooldown(int delta);

  /**
   * @brief Updates the duration of the special effect
   * 
   * @param delta  int (time elapsed)
   */
  void updateDuration(int delta);

  /**
   * @brief Returns the current cooldown as a string, rounded to the first
   * digit. Returns "Ready" if the cooldown is null.
   *
   * @return std::string
   */
  std::string getCDStr();

  virtual ~Weapon();

  /**
   * @brief Main shot
   *
   */
  virtual void fire() = 0;

  /**
   * @brief Special shot
   *
   */
  virtual void fireSpecial() = 0;

  /**
   * @brief Process collisions between the weapon element(s) and a vector
   * of Asteroids. Returns the indexes of the matched asteroids.
   *
   * @return std::vector<int> indexes that must be processed in the vector of
   * Asteroids
   */
  virtual std::vector<int> collided(std::vector<Asteroid *>) = 0;

  /**
   * @brief Updates the weapon in SDL
   *
   * @param width
   * @param height
   */
  virtual void update(int width, int height) = 0;

  /**
   * @brief Draws the weapon
   *
   * @param renderer
   */
  virtual void draw(SDL_Renderer *renderer) = 0;
};

#endif