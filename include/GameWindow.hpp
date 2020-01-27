#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Spaceship.hpp"
#include <vector>
#include <random>

#define DELTA_ANGLE 0.15f

class GameWindow {
  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Spaceship *spaceship;
    vector<Asteroid*> asteroids;
    
    int width;
    int height;

  public:
    GameWindow(const char *name, int width, int height);
    ~GameWindow();
    void initShip(vec2 position);
    void initAsteroids(int number);
    void updateAsteroids();
    void draw();
    void mainLoop();

};

#endif