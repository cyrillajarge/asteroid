#include "SDL2/SDL.h"
#include "Spaceship.hpp"
#include <memory>

#define DELTA_ANGLE 0.15

typedef enum input_mapping_e { MAPPING_P1, MAPPING_P2 } input_mapping_t;

struct keymap {
  SDL_Scancode left;
  SDL_Scancode right;
  SDL_Scancode prop;
  SDL_Scancode spec;
  SDL_Scancode fire;
  SDL_Scancode weapon_switch;
};

class InputManager {
public:
  /**
   * @brief Delta angle then the spaceship rotates
   *
   */
  double deltaRotation = 0.;

  /**
   * @brief Keyboard mappings
   *
   */
  struct keymap mapper;

  /**
   * @brief Timestamp when last shot was fired
   *
   */
  int last_shot = 0;

  /**
   * @brief Timestalp--mp when last weapon was changed
   * 
   */
  int last_weapon_switch = 0;

private:
  /**
   * @brief Points to the spaceship instance it handles
   *
   */
  std::weak_ptr<Spaceship> spaceship;

public:
  InputManager(input_mapping_t kind);
  ~InputManager();
  /**
   * @brief Process user inputs
   *
   * @param current_time
   */
  void process(int current_time);

  /**
   * @brief Attach a spaceship to this object
   *
   * @param s
   */
  void attach(std::shared_ptr<Spaceship> s);

private:
  /**
   * @brief Initialize mappings
   *
   * @param kind
   */
  void initMapper(input_mapping_t kind);
};