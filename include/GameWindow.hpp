#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Spaceship.hpp"
#include "Font.hpp"
#include "Menu.hpp"
#include "Player.hpp"
#include "UI/UIComponent.hpp"
#include "Particles/ParticlesManager.hpp"
#include "Sound/SoundManager.hpp"
#include <vector>

#define DELTA_ANGLE 0.15f

enum GAME_STATE {
  STOPPED,
  MENU,
  GAME
};

class GameWindow {
  public:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Spaceship *spaceship;
    ParticlesManager *particleManager;
    Font *font;
    Menu *menu;
    SoundManager* soundManager;
    std::vector<Asteroid*> asteroids;
    Player *p1;
    int width;
    int height;
    GAME_STATE state;

  public:
    GameWindow(const char *name, int width, int height);
    ~GameWindow();
    void initShip(glm::vec2 position, int size);
    void initAsteroids(int number);
    void initGame();
    void endGame(); // RIP TONY STARK
    void updateAsteroids();
    void updateScore(int level);
    void draw();
    void mainLoop();

};

#endif