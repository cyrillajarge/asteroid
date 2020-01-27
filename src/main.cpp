#include <iostream>
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>

#include "SDL2/SDL.h"
#include "GameWindow.hpp"
#include "Spaceship.hpp"
#include "Rocket.hpp"

using namespace std;
using namespace glm;

#define WIDTH 1080
#define HEIGHT 720
#define DELTA_ANGLE 0.15f

int main(int argc, char* argv[]) {

  if( SDL_Init( SDL_INIT_EVERYTHING) < 0){
      cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
      return EXIT_FAILURE;
  }

  GameWindow *window = new GameWindow("Hemoroids", WIDTH, HEIGHT);

  vec2 position = vec2(WIDTH / 2.0f, HEIGHT / 2.0f);
  window->InitShip(position);

  // vec2 rocket_pos = vec2(40.0f,40.0f);
  // Rocket* rocket = new Rocket(rocket_pos);
  // rocket->draw(renderer);
  window->MainLoop();
  
  delete window;
  SDL_Quit();
  return EXIT_SUCCESS;
}

