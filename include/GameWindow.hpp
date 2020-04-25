#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Font.hpp"
#include "Menu.hpp"
#include "Particles/ParticlesManager.hpp"
#include "Player.hpp"
#include "Scoreboard.hpp"
#include "UI/UIComponent.hpp"
#include <memory>
#include <vector>
#include <mutex>

enum GAME_STATE { STOPPED, MENU, GAME, END_MENU, SCOREBOARD_MENU };

class GameWindow {
public:
  SDL_Window *window;
  SDL_Renderer *renderer;
  std::unique_ptr<ParticlesManager> particleManager;
  Font *font;
  std::unique_ptr<Menu> menu;
  std::unique_ptr<Menu> end_menu;
  std::unique_ptr<Menu> scoreboard_menu;
  std::vector<Asteroid *> asteroids;
  std::unique_ptr<LevelsManager> levels_manager;
  std::unique_ptr<Player> players[2];
  std::unique_ptr<Scoreboard> scoreboard;
  std::mutex mutex;
  bool coop_mode = false;
  int width;
  int height;
  GAME_STATE state;
  GAME_STATE previous_state;

private:
  void processPlayer(int num_player, int current_time);

public:
  GameWindow(const char *name, int width, int height);
  ~GameWindow();

  /**
  * @brief Initialize main menu with its components
  */
  void initMenu();

  /**
  * @brief Initialize end menu with its components
  */
  void initEndMenu();
  
  /**
  * @brief Initialize scoreboard menu with its components
  */
  void initScoreboardMenu();
  
  /**
  * @brief Increments level and sets everything that depends on it
  */
  void nextLevel();

  /**
  * @brief Adds asteroids to the game
  * 
  * @param number
  */
  void initAsteroids(int number);
  
  /**
   * @brief Inits players depending on coop mode or not
   */
  void initPlayers();

  /**
  * @brief Initialize game and everything that depends on it
  */
  void initGame();

  /**
  * @brief Changes state to END_GAME and sets display for end menu
  */
  void endGame(); // RIP TONY STARK

  /**
  * @brief Updates asteroids positions
  */
  void updateAsteroids();

  /**
  * @brief Updates score
  * 
  * @param player
  * @param level
  */
  void updateScore(int player, int level);

  /**
  * @brief Main draw, called at a regular time interval
  */
  void draw();

  /**
  * @brief Main game loop
  */
  void mainLoop();

  /**
  * @brief Manages asteroids: checks collisions, debris(particles), asteroids subdivisions
  * @param collided
  */
  void computeAsteroids(int player);
};

#endif