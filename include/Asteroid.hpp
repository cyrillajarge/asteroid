#ifndef ASTEROID_H
#define ASTEROID_H

#include <cmath>
#include <random>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include "glm/glm.hpp"
#include "SDL2/SDL.h"

using namespace glm;
using namespace std;

class Asteroid {
  public:
    vec2 center;
    vector<int> rays;
    int averageray;
    vector<vec2> BB;
    int  nrays;
    vec2 direction;

  public:
    Asteroid(vec2 position, vec2 direction, int averageray, int nrays);
    ~Asteroid();
    void computeBB();
    void draw(SDL_Renderer* renderer);
};

#endif