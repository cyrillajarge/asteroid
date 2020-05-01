#include <iostream>
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>

#include "GameWindow.hpp"
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

  GameWindow *window = new GameWindow("Asteroids", WIDTH, HEIGHT);

  window->mainLoop();

  delete window;
  SDL_Quit();
  return EXIT_SUCCESS;
}
