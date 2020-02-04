#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Spaceship.hpp"
#include "Font.hpp"
#include "Menu.hpp"
#include "Player.hpp"
#include <vector>

#define DELTA_ANGLE 0.15f

class GameWindow {
  public:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Spaceship *spaceship;
    Font *font;
    Menu* menu;
    std::vector<Asteroid*> asteroids;
    Player *p1;
    int width;
    int height;
    bool started;

  public:
    GameWindow(const char *name, int width, int height);
    ~GameWindow();
    void initShip(glm::vec2 position, int size);
    void initAsteroids(int number);
    void updateAsteroids();
    void updateScore(int level);
    void draw();
    void mainLoop();

};

#endif