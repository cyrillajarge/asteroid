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


void GameWindow::InitShip(vec2 position) {
  this->spaceship = new Spaceship(position, this->renderer);
}

void GameWindow::MainLoop(void) {
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
        this->spaceship->activateBoost();
      }
      if(keystates[SDL_SCANCODE_SPACE]){
        this->spaceship->fireRocket();
      }
      this->spaceship->update(deltaRotation, this->width, this->height);
      this->spaceship->draw();
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