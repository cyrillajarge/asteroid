#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "SDL2/SDL.h"
#include "glm/glm.hpp"
#include "Rocket.hpp"
#include <list>
#include <iterator>

using namespace std;
using namespace glm;

#define VEL_ATTENUATION 0.98f
#define DIR_VECTOR_REGULATION 0.4f

class Spaceship {
  public:
    vec2 position;
    SDL_Renderer* renderer;
    double direction_angle;
    vec2 velocity;
    bool boostActive;
    list<Rocket*> rockets;

  public:
    Spaceship(vec2 position, SDL_Renderer* renderer);
    void activateBoost();
    void deactivateBoost();
    void update(double rotation, int width, int height);
    void boost();
    void fireRocket(Rocket* rocket);
    void draw();

};

#endif