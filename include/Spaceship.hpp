#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "SDL2/SDL.h"
#include "glm/glm.hpp"
#include "Rocket.hpp"
#include "Asteroid.hpp"
#include "Player.hpp"
#include <list>
#include <vector>
#include <iterator>

#define VEL_ATTENUATION 0.98f
#define DIR_VECTOR_REGULATION 0.4f

class Spaceship {
  public:
    Player *player;
    glm::vec2 position;
    double direction_angle;
    glm::vec2 velocity;
    bool boostActive;
    int size;
    std::vector<Rocket*> rockets;

  public:
    Spaceship(Player *p, glm::vec2 position, int size);
    void activateBoost();
    void deactivateBoost();
    void update(double rotation, int width, int height);
    void boost();
    void fireRocket(Rocket* rocket);
    bool intersectsAsteroid(std::vector<Asteroid*> asteroids);
    void draw(SDL_Renderer* renderer);

};

#endif