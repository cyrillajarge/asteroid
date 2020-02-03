#include <iostream>
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>

#include "SDL2/SDL.h"
#include "GameWindow.hpp"
#include "Spaceship.hpp"
#include "Rocket.hpp"

#define WIDTH 1080
#define HEIGHT 720
#define DELTA_ANGLE 0.15f

int main(int argc, char* argv[]) {

  if(SDL_Init( SDL_INIT_EVERYTHING) < 0){
      std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
      return EXIT_FAILURE;
  }

  GameWindow *window = new GameWindow("Hemoroids", WIDTH, HEIGHT);

  glm::vec2 position = glm::vec2(WIDTH / 2.0f, HEIGHT / 2.0f);
  window->initShip(position, 20);

  // vec2 rocket_pos = vec2(40.0f,40.0f);
  // Rocket* rocket = new Rocket(rocket_pos);
  // rocket->draw(renderer);
  window->mainLoop();
  
  delete window;
  SDL_Quit();
  return EXIT_SUCCESS;
}

