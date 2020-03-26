#include "SDL2/SDL.h"
#include "Spaceship.hpp"
#include <memory>

#define DELTA_ANGLE 0.15

typedef enum input_mapping_e {
  MAPPING_P1,
  MAPPING_P2
} input_mapping_t;

struct keymap {
  SDL_Scancode left;
  SDL_Scancode right;
  SDL_Scancode prop;
  SDL_Scancode spec;
  SDL_Scancode fire;
};

class InputManager {
  public:
    double deltaRotation = 0.;
    struct keymap mapper;
    int last_shot = 0;
  
  private:
    std::weak_ptr<Spaceship> spaceship;

  public:
    InputManager(input_mapping_t kind);
    ~InputManager();
    void process(int current_time);
    void attach(std::shared_ptr<Spaceship> s);
    
  private: 
    void initMapper(input_mapping_t kind);
};