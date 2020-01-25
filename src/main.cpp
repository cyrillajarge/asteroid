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

  vec2 position = vec2(200.0f,200.0f);
  Spaceship* uss_enterprise = new Spaceship(position,renderer);
  uss_enterprise->draw(false);

  double angle = 0.0f;
  double delta_angle = 180.0f;
  double acceleration = 0.2f;
  double deceleration = 0.02f;
  double speed = 150.0f;
  vec2 dir = vec2(0.0f, 0.0f);
  vec2 motion = vec2(0.0f, 0.0f);
  int lastTime = 0, currentTime = 0;


  double deltaTime = 0.0f;
  double test = 0.0f;
  double last_angle = 0.0f;
  bool accelerationmarker = false;

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
          angle -= 0.05f * delta_angle;
          uss_enterprise->rotate(angle);
        }
        if (keystates[SDL_SCANCODE_RIGHT]) {
          angle += 0.05f * delta_angle;
          uss_enterprise->rotate(angle);
        }
        if(keystates[SDL_SCANCODE_UP]) {
          accelerationmarker = true;
          dir = vec2(cos(uss_enterprise->angle), sin(uss_enterprise->angle));
          if(angle != last_angle){
            motion = length(motion) * dir;
            last_angle = angle;
          }

          if(abs(motion.x - dir.x) >= 0.0001f || abs(motion.y - dir.y) >= 0.0001f){
            double dist = distance(motion, 2.0f * dir);
            motion += dir * (float)dist * (float)acceleration;
          }
        }
        if( abs(motion.x) > 0.0f || abs(motion.y) > 0.0f){
          double dist = distance(vec2(0.0f, 0.0f), motion);
          if(dist > 0.1f){
            motion -= dir * (float)dist * (float)deceleration;
          }
          else{
            motion = vec2(0.0f, 0.0f);
          }
        }

        uss_enterprise->position += motion * (float)speed * 0.03f;
        uss_enterprise->draw(accelerationmarker);
        accelerationmarker = false;
        lastTime = currentTime;
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}

