#include "GameWindow.hpp"
#include <iostream>

GameWindow::GameWindow(const char *name, int width, int height) {
  // Create window
  this->window = SDL_CreateWindow(name,
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    width, height,
    SDL_WINDOW_RESIZABLE
  );
  if(this->window == NULL){
    cerr << "Could not create window: " << SDL_GetError() << endl;
    exit(EXIT_FAILURE);
  }
  this->width = width;
  this->height = height;

  // Create renderer
  this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
  if(this->renderer == NULL){
    cerr << "Could not create renderer: " << SDL_GetError() << endl;
    exit(EXIT_FAILURE);
  }

  this->spaceship = NULL;
}


void GameWindow::initShip(vec2 position) {
  this->spaceship = new Spaceship(position);
}

void GameWindow::mainLoop(void) {
  int deltaTime = 0, lastTime = 0, currentTime = 0, lastRocket = 0;
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
        this->spaceship->activateBoost();
      }
      if ((keystates[SDL_SCANCODE_SPACE]) && (currentTime - lastRocket > 200)) {
        vec2 rocket_dir = vec2(cos(this->spaceship->direction_angle), sin(this->spaceship->direction_angle));
        Rocket* rocket = new Rocket(this->spaceship->position + 30.0f * rocket_dir, rocket_dir);
        this->spaceship->fireRocket(rocket);
        lastRocket = currentTime;
      }
      this->spaceship->update(deltaRotation, this->width, this->height);
      this->spaceship->draw(this->renderer);
      deltaRotation = 0.0f;
      this->spaceship->deactivateBoost();
      lastTime = currentTime;
    }
  }
}


GameWindow::~GameWindow(void) {
  SDL_DestroyWindow(this->window);
  SDL_DestroyRenderer(this->renderer);
  delete this->spaceship;

}