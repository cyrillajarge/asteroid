#include <iostream>
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>

#include "GameWindow.hpp"
#include "Rocket.hpp"
#include "SDL2/SDL.h"
#include "Spaceship.hpp"

#define WIDTH 1080
#define HEIGHT 720

int main() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError()
              << std::endl;
    return EXIT_FAILURE;
  }

  GameWindow *window = new GameWindow("Hemoroids", WIDTH, HEIGHT);

  // vec2 rocket_pos = vec2(40.0f,40.0f);
  // Rocket* rocket = new Rocket(rocket_pos);
  // rocket->draw(renderer);
  window->mainLoop();

  delete window;
  SDL_Quit();
  return EXIT_SUCCESS;
}
