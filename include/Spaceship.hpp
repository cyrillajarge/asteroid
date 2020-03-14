#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "SDL2/SDL.h"
#include "glm/glm.hpp"
#include "Rocket.hpp"
#include "Asteroid.hpp"
#include "Player.hpp"
#include "Particles/ParticlesManager.hpp"
#include "Particles/LifeParticle.hpp"
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
    ParticlesManager* pmship;
    int size;
    std::vector<Rocket*> rockets;
    int cooldown;

  public:
    Spaceship(Player *p, glm::vec2 position, int size);
    ~Spaceship();
    void activateBoost();
    void deactivateBoost();
    void update(double rotation, int width, int height);
    void boost();
    void fireRocket();
    void fireSpecial();
    bool intersectsAsteroid(std::vector<Asteroid*> asteroids);
    void draw(SDL_Renderer* renderer);
    glm::vec2 getDirection();

};

#endif