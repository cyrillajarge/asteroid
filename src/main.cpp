#include <iostream>
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>

#include "SDL2/SDL.h"
#include "Spaceship.hpp"

using namespace std;
using namespace glm;

const int WIDTH = 800, HEIGHT = 600; 


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

  vec2 base_dir = vec2(1.0f,0.0f);
  vec2 position = vec2(200.0f,200.0f);
  Spaceship* uss_enterprise = new Spaceship(position,0,base_dir,renderer);
  uss_enterprise->draw();

  double angle = 0.0f;
  double delta_angle = M_PI/64.0f;
  double speed = 1.0f;

  SDL_Event windowEvent;
  while(true){
    if(SDL_PollEvent( &windowEvent)){
      if(SDL_QUIT == windowEvent.type){
        break;
      }
    }
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if(keystates[SDL_SCANCODE_LEFT] && keystates[SDL_SCANCODE_UP]){
      cout << "rotate left and acceleration" << endl;
      angle -= 0.3f * delta_angle;
      uss_enterprise->setDirection(angle);
      uss_enterprise->accelerate(speed);
      uss_enterprise->draw();
    }
    else if(keystates[SDL_SCANCODE_RIGHT] && keystates[SDL_SCANCODE_UP]){
      cout << "rotate right and acceleration" << endl;
      angle += 0.3f * delta_angle;
      uss_enterprise->setDirection(angle);
      uss_enterprise->accelerate(speed);
      uss_enterprise->draw();
    }
    else if (keystates[SDL_SCANCODE_LEFT]) {
      cout << "rotate right " << angle << endl;
      angle -= 0.3f * delta_angle;
      uss_enterprise->setDirection(angle);
      uss_enterprise->draw();
    }
    else if (keystates[SDL_SCANCODE_RIGHT]) {
      cout << "rotate left" << endl;
      angle += 0.3f * delta_angle;
      uss_enterprise->setDirection(angle);
      uss_enterprise->draw();
    }
    else if(keystates[SDL_SCANCODE_UP]) {
      cout << "acceleration" << endl;
      uss_enterprise->accelerate(speed);
      uss_enterprise->draw();
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}

