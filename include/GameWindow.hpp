#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Font.hpp"
#include "Menu.hpp"
#include "Particles/ParticlesManager.hpp"
#include "Player.hpp"
#include "UI/UIComponent.hpp"
#include <memory>
#include <vector>

enum GAME_STATE { STOPPED, MENU, GAME, END_MENU };

class GameWindow {
public:
  SDL_Window *window;
  SDL_Renderer *renderer;
  std::unique_ptr<ParticlesManager> particleManager;
  Font *font;
  std::unique_ptr<Menu> menu;
  std::unique_ptr<Menu> end_menu;
  std::vector<Asteroid *> asteroids;
  std::unique_ptr<Player> players[2];
  int width;
  int height;
  GAME_STATE state;

public:
  GameWindow(const char *name, int width, int height);
  ~GameWindow();
  void initMenu();
  void initEndMenu();
  void initAsteroids(int number);
  void initGame();
  void endGame(); // RIP TONY STARK
  void updateAsteroids();
  void updateScore(int level);
  void draw();
  void mainLoop();
  void computeAsteroids(std::vector<int> collided);
};

#endif