#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Spaceship.hpp"

#define DELTA_ANGLE 0.15f

class GameWindow {
  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Spaceship *spaceship;
    int width;
    int height;
  public:
    GameWindow(const char *name, int width, int height);
    ~GameWindow();
    void initShip(vec2 position);
    void mainLoop();

};

#endif