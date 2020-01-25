#include <iostream>
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>

#include "SDL2/SDL.h"
#include "Spaceship.hpp"

using namespace std;
using namespace glm;

#define WIDTH 800
#define HEIGHT 600
#define DELTA_ANGLE 0.15f

int main(int argc, char* argv[]) {

  if( SDL_Init( SDL_INIT_EVERYTHING) < 0){
      cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
      return EXIT_FAILURE;
  }

  SDL_Window *window = SDL_CreateWindow("Asteroid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

  if( window == NULL){
    cout << "Could not create window: " << SDL_GetError() << endl;
    return EXIT_FAILURE;
  }


  SDL_Renderer* renderer = NULL;
  renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

  int window_width;
  int window_height;
  SDL_GetWindowSize(window, &window_width, &window_height);

  vec2 position = vec2(window_width / 2.0f, window_height / 2.0f);
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
        uss_enterprise->update(deltaRotation);
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

