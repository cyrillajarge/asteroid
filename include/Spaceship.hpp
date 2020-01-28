#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "SDL2/SDL.h"
#include "glm/glm.hpp"
#include "Rocket.hpp"
#include "Asteroid.hpp"
#include <list>
#include <iterator>

#define VEL_ATTENUATION 0.98f
#define DIR_VECTOR_REGULATION 0.4f

class Spaceship {
  public:
    glm::vec2 position;
    double direction_angle;
    glm::vec2 velocity;
    bool boostActive;
    std::vector<Rocket*> rockets;
    Asteroid* asteroid;

  public:
    Spaceship(glm::vec2 position);
    void activateBoost();
    void deactivateBoost();
    void update(double rotation, int width, int height);
    void boost();
    void fireRocket(Rocket* rocket);
    void draw(SDL_Renderer* renderer);

};

#endif