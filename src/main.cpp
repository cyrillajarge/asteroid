#include <iostream>
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>

#include "SDL2/SDL.h"
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

  SDL_Window *window = SDL_CreateWindow("Asteroid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);

  if( window == NULL){
    cout << "Could not create window: " << SDL_GetError() << endl;
    return EXIT_FAILURE;
  }

  SDL_Renderer* renderer = NULL;
  renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

  vec2 position = vec2(WIDTH / 2.0f, HEIGHT / 2.0f);
  Spaceship* uss_enterprise = new Spaceship(position,renderer);

  int lastTime = 0, currentTime = 0;

  double deltaTime = 0.0f;
  double deltaRotation = 0.0f;

  SDL_Event windowEvent;
  while(true){
    if(SDL_PollEvent( &windowEvent)){
      if(SDL_QUIT == windowEvent.type){
        break;
      }
    }
    currentTime = SDL_GetTicks();
    deltaTime = currentTime - lastTime;
    if (deltaTime > 30) /* Si 30 ms se sont écoulées */
    {
        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        if (keystates[SDL_SCANCODE_LEFT]) {
          deltaRotation = -DELTA_ANGLE;
        }
        if (keystates[SDL_SCANCODE_RIGHT]) {
          deltaRotation = DELTA_ANGLE;
        }
        if(keystates[SDL_SCANCODE_UP]) {
          uss_enterprise->activateBoost();
        }
        if(keystates[SDL_SCANCODE_SPACE]){
          vec2 rocket_dir = vec2(cos(uss_enterprise->direction_angle), sin(uss_enterprise->direction_angle));
          Rocket* rocket = new Rocket(uss_enterprise->position + 30.0f * rocket_dir, rocket_dir);
          uss_enterprise->fireRocket(rocket);
        }
        uss_enterprise->update(deltaRotation, WIDTH, HEIGHT);
        uss_enterprise->draw();
        
        deltaRotation = 0.0f;
        uss_enterprise->deactivateBoost();
        lastTime = currentTime;
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  delete uss_enterprise;
  return EXIT_SUCCESS;
}

