#include "GameWindow.hpp"
#include "Font.hpp"
#include <iostream>
#include <random>
#include <string>

GameWindow::GameWindow(const char *name, int width, int height) {
  // Create window
  this->window =
      SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                       width, height, SDL_WINDOW_RESIZABLE);
  if (this->window == NULL) {
    std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
    std::exit(EXIT_FAILURE);
  }
  this->width = width;
  this->height = height;

  // Create renderer
  this->renderer =
      SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
  if (this->renderer == NULL) {
    std::cerr << "Could not create renderer: " << SDL_GetError() << std::endl;
    std::exit(EXIT_FAILURE);
  }
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

  this->spaceship = nullptr;
  this->font = new Font({255, 255, 255, 255});
  this->p1 = new Player();
  this->menu = new Menu(this->font);
  // this->initAsteroids(1);
  this->state = MENU;
  this->menu->components[0]->handler = [this]() {
    this->state = GAME;
    this->initGame();
  };
}

void GameWindow::initShip(glm::vec2 position, int size) {
  this->spaceship = new Spaceship(this->p1, position, size);
}

void GameWindow::initAsteroids(int number) {

  for (int i = 0; i < number; i++) {
    int posx = -10.0f + std::rand() % (this->width + 10);
    int posy = -10.0f + std::rand() % (this->height + 10);

    int angle = std::rand() % 360;
    // float angle_rad = (angle / 180.0f)* M_PI;

    glm::vec2 position = glm::vec2(posx, posy);
    glm::vec2 direction = glm::vec2(cos(angle), sin(angle));

    this->asteroids.push_back(new Asteroid(position, direction, 40, 12, 2));
  }
}

void GameWindow::initGame() {
  glm::vec2 position = glm::vec2(this->width / 2.0f, this->height / 2.0f);
  this->initShip(position, 20);
  this->initAsteroids(6);
}

void GameWindow::updateAsteroids() {
  for (size_t i = 0; i < this->asteroids.size(); i++) {
    if (this->asteroids[i]->center.x < 0) {
      this->asteroids[i]->center.x = this->width;
    }
    if (this->asteroids[i]->center.x > width) {
      this->asteroids[i]->center.x = 0;
    }
    if (this->asteroids[i]->center.y < 0) {
      this->asteroids[i]->center.y = this->height;
    }
    if (this->asteroids[i]->center.y > height) {
      this->asteroids[i]->center.y = 0;
    }

    this->asteroids[i]->center += 2.0f * this->asteroids[i]->direction;
  }
}

void GameWindow::updateScore(int level) {
  switch (level) {
  case 2:
    this->p1->score += 20;
    break;
  case 1:
    this->p1->score += 50;
    break;
  case 0:
    this->p1->score += 100;
    break;
  }
}

void GameWindow::draw() {
  // Set render color to black ( background will be rendered in this color )
  SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);

  // // Clear winow
  SDL_RenderClear(this->renderer);

  if (this->state == MENU) {
    this->menu->draw(this->renderer, this->width, this->height);
  } else if (this->state == GAME) {
    this->font->drawText(this->renderer, "Score :", 50, 50);
    std::string score = std::to_string(this->p1->score);
    this->font->drawText(this->renderer, score, 200, 50);

    this->spaceship->draw(this->renderer);

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);

    for (size_t i = 0; i < this->asteroids.size(); i++) {
      this->asteroids[i]->draw(this->renderer);
    }
  }
  // Render the rect to the screen
  SDL_RenderPresent(renderer);
}

void GameWindow::mainLoop(void) {
  int deltaTime = 0, lastTime = 0, currentTime = 0, lastRocket = 0;
  double deltaRotation = 0.0f;

  SDL_Event windowEvent;
  while (this->state != STOPPED) {
    if (SDL_PollEvent(&windowEvent)) {
      switch(windowEvent.type) {
        case SDL_QUIT:
          this->state = STOPPED;
          break;
        case SDL_MOUSEBUTTONDOWN:
          for (UIComponent *comp : this->menu->components) {
            if (comp->isIn(windowEvent.button.x, windowEvent.button.y)) {
              comp->handler();
            }
          }
        default: break;
      }
    }
    if (this->state == GAME) {
      currentTime = SDL_GetTicks();
      deltaTime = currentTime - lastTime;
      if (deltaTime > 30) /* Si 30 ms s@e sont écoulées */
      {
        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        if (keystates[SDL_SCANCODE_LEFT]) {
          deltaRotation = -DELTA_ANGLE;
        }
        if (keystates[SDL_SCANCODE_RIGHT]) {
          deltaRotation = DELTA_ANGLE;
        }
        if (keystates[SDL_SCANCODE_UP]) {
          this->spaceship->activateBoost();
        }
        if ((keystates[SDL_SCANCODE_SPACE]) && (currentTime - lastRocket > 200)) {
          glm::vec2 rocket_dir = glm::vec2(cos(this->spaceship->direction_angle),
                                          sin(this->spaceship->direction_angle));
          Rocket *rocket = new Rocket(
              this->spaceship->position + 30.0f * rocket_dir, rocket_dir);
          this->spaceship->fireRocket(rocket);
          lastRocket = currentTime;
        }

        int inter;
        auto it = this->spaceship->rockets.begin();
        while (it != this->spaceship->rockets.end()) {
          inter = (*it)->intersectsAsteroid(this->asteroids);
          if (inter != -1) {
            it = this->spaceship->rockets.erase(it);
            glm::vec2 aster_pos = this->asteroids[inter]->center;
            int ar = this->asteroids[inter]->averageray;
            int nr = this->asteroids[inter]->nrays;
            int lev = this->asteroids[inter]->level;

            this->updateScore(lev);

            this->asteroids.erase(this->asteroids.begin() + inter);
            if (lev > 0) {
              for (int i = 0; i < 2; i++) {
                double angle = ((rand() % 360) / 180.0f) * M_PI;
                glm::vec2 dir = glm::vec2(cos(angle), sin(angle));
                this->asteroids.push_back(
                    new Asteroid(aster_pos, dir, ar / 2, nr, lev - 1));
              }
            }
          } else {
            ++it;
          }
        }

        // inter = this->spaceship->blade->intersectsAsteroid(this->asteroids);
        // if (inter != -1) {
        //   glm::vec2 aster_pos = this->asteroids[inter]->center;
        //   int ar = this->asteroids[inter]->averageray;
        //   int nr = this->asteroids[inter]->nrays;
        //   int lev = this->asteroids[inter]->level;

        //   this->updateScore(lev);

        //   this->asteroids.erase(this->asteroids.begin() + inter);
        //   if (lev > 0) {
        //     for (int i = 0; i < 2; i++) {
        //       double angle = ((rand() % 360) / 180.0f) * M_PI;
        //       glm::vec2 dir = glm::vec2(cos(angle), sin(angle));
        //       this->asteroids.push_back(
        //           new Asteroid(aster_pos, dir, ar / 2, nr, lev - 1));
        //     }
        //   }
        // }

        if (this->spaceship->intersectsAsteroid(this->asteroids)) {
          this->state = STOPPED;
        }

        this->spaceship->update(deltaRotation, this->width, this->height);
        this->updateAsteroids();
        this->draw();

        deltaRotation = 0.0f;
        this->spaceship->deactivateBoost();
        lastTime = currentTime;
      }
    } else if (this->state == MENU) {
      this->draw();
    }
  }
}

GameWindow::~GameWindow(void) {
  SDL_DestroyWindow(this->window);
  SDL_DestroyRenderer(this->renderer);
  delete this->spaceship;
  delete this->menu;
  delete this->font;
  delete this->p1;
}