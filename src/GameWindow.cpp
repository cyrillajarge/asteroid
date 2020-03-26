#include "GameWindow.hpp"
#include "Font.hpp"
#include "Random/Alea.hpp"
#include "UI/Checkbox.hpp"
#include "UI/Clickable.hpp"
#include "UI/TextInput.hpp"
#include <iostream>
#include <random>
#include <string>
#include <utility>

GameWindow::GameWindow(const char *name, int width, int height) {
  // Create window
  this->window =
      SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                       width, height, SDL_WINDOW_RESIZABLE);
  if (this->window == NULL) {
    std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
    std::exit(EXIT_FAILURE);
  }

  // Setting game window properties
  this->width = width;
  this->height = height;

  // Particle Manager
  this->particleManager = std::make_unique<ParticlesManager>();

  // Create renderer
  this->renderer =
      SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
  if (this->renderer == NULL) {
    std::cerr << "Could not create renderer: " << SDL_GetError() << std::endl;
    std::exit(EXIT_FAILURE);
  }
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

  // Setting up game entities
  this->p1 = std::make_unique<Player>();

  // Setting up UI
  this->font = new Font({255, 255, 255, 255});
  UIComponent::font = this->font;
  this->menu = new Menu(this->font);
  this->menu->addPlainText("title", "ASTEROID", {200, 200});
  this->menu->components["title"]->center(width, height);
  this->menu->components["title"]->moveY(-200);

  this->menu->addButton("play", "PLAY", {200, 200});
  this->menu->components["play"]->border = true;
  this->menu->components["play"]->border_color = {0, 255, 0, 255};
  this->menu->components["play"]->center(width, height);

  this->menu->addPlainText("score", "No score yet", {400, 400});
  this->menu->components["score"]->enabled = false;
  this->menu->components["score"]->center(width, height);
  this->menu->components["score"]->moveY(100);

  this->menu->addTextInput("gamertag", "Enter Gamertag:",{400, 400});
  this->menu->components["gamertag"]->center(width, height);
  this->menu->components["gamertag"]->moveY(150);

  this->end_menu = new Menu(this->font);
  this->end_menu->addPlainText("message", "LMAO u ded!!", {200,200});
  this->end_menu->components["message"]->center(width, height);
  this->end_menu->components["message"]->moveY(-200);

  this->end_menu->addPlainText("score", "Your score : " + std::to_string(this->p1->score), {400, 400});
  this->end_menu->components["score"]->center(width, height);

  this->end_menu->addButton("playa", "Play Again", {200,200});
  this->end_menu->components["playa"]->center(width, height);
  this->end_menu->components["playa"]->moveY(200);
  this->end_menu->components["playa"]->border = true;
  this->end_menu->components["playa"]->border_color = {0, 255, 0, 255};

  // this->initAsteroids(1);
  this->state = MENU;
  dynamic_cast<Clickable *>(this->menu->components["play"])->handler =
      [this](){ 
        this->p1->name = dynamic_cast<TextInput *>(this->menu->components["gamertag"])->input;
        this->initGame();
      };

  dynamic_cast<Clickable *>(this->end_menu->components["playa"])->handler =
      [this](){ 
        this->p1->score = 0;
        this->initGame();
      };

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
  if (this->state != GAME) {
    this->state = GAME;
    glm::vec2 position = glm::vec2(this->width / 2.0f, this->height / 2.0f);
    this->p1->initShip(position, 20);
    this->initAsteroids(6);
  }
}

void GameWindow::endGame() {
  this->state = END_MENU;
  this->asteroids.clear();
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
    this->menu->draw(this->renderer);
  } else if (this->state == END_MENU){
    this->end_menu->draw(this->renderer);
  } else {
    int eos;
    // Draw score
    eos = this->font->drawText(this->renderer, "Score :", 50, 50);
    std::string score = std::to_string(this->p1->score);
    this->font->drawText(this->renderer, score, eos + 20, 50);

    // Draw special cooldown

    eos = this->font->drawText(this->renderer, "Special CD :", 700, 50);

    this->font->drawText(this->renderer, this->p1->spaceship->weapon->getCDStr(),
                         eos + 20, 50);

    this->p1->spaceship->draw(this->renderer);

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);

    for (size_t i = 0; i < this->asteroids.size(); i++) {
      this->asteroids[i]->draw(this->renderer);
    }

    this->particleManager->drawParticles(this->renderer);
  }
  // Render the rect to the screen
  SDL_RenderPresent(renderer);
}

void GameWindow::mainLoop(void) {
  int deltaTime = 0, lastTime = 0, currentTime = 0;

  auto gen_float = alea_generator(-1.0f, 1.0f);

  SDL_Event windowEvent;
  while (this->state != STOPPED) {
    if (SDL_PollEvent(&windowEvent)) {
      switch (windowEvent.type) {
      case SDL_QUIT:
        this->state = STOPPED;
        break;
      case SDL_MOUSEBUTTONDOWN:
        if(this->state == MENU || this->state == END_MENU){
          for (std::pair<std::string, UIComponent *> _comp :
              this->menu->components) {
            if (Clickable *comp = dynamic_cast<Clickable *>(_comp.second)) {
              if (comp->isIn(windowEvent.button.x, windowEvent.button.y)) {
                comp->handler();
              }
            }
          }
        }
      case SDL_TEXTINPUT:
        if(this->state == MENU){
				  dynamic_cast<TextInput *>(this->menu->components["gamertag"])->addLetter(windowEvent);
        }
				break;
			case SDL_KEYDOWN:
        if(this->state == MENU){
          if(windowEvent.key.keysym.sym == SDLK_BACKSPACE){
				    dynamic_cast<TextInput *>(this->menu->components["gamertag"])->removeLetter(windowEvent);
          }
          if(windowEvent.key.keysym.sym == SDLK_RETURN){
            this->p1->name = dynamic_cast<TextInput *>(this->menu->components["gamertag"])->input;
            this->initGame();
          }
        }
				break;
      default:
        break;
      }
    }
    if (this->state == GAME) {
      currentTime = SDL_GetTicks();
      deltaTime = currentTime - lastTime;
      if (deltaTime > 30) /* Si 30 ms s@e sont écoulées */
      {
        this->p1->input_manager->process(currentTime);

        for (int inter : this->p1->spaceship->weapon->collided(this->asteroids)) {
          glm::vec2 aster_pos = this->asteroids[inter]->center;
          int ar = this->asteroids[inter]->averageray;
          int nr = this->asteroids[inter]->nrays;
          int lev = this->asteroids[inter]->level;

          this->updateScore(lev);

          this->asteroids.erase(this->asteroids.begin() + inter);
          for (int i = 0; i < 10; i++) {
            float speedx = gen_float();
            float speedy = gen_float();
            this->particleManager->addParticle(
                new LifeParticle(glm::vec4(0, 255, 0, 255), aster_pos,
                                 glm::vec2(speedx, speedy), 50));
          }
          if (lev > 0) {
            for (int i = 0; i < 2; i++) {
              double angle = ((rand() % 360) / 180.0f) * M_PI;
              glm::vec2 dir = glm::vec2(cos(angle), sin(angle));
              this->asteroids.push_back(
                  new Asteroid(aster_pos, dir, ar / 2, nr, lev - 1));
            }
          }
        }

        if (this->p1->spaceship->intersectsAsteroid(this->asteroids)) {
          this->endGame();
        }

        this->p1->spaceship->update(this->p1->getDelta(), this->width, this->height);
        this->updateAsteroids();
        this->particleManager->updateParticles();
        this->draw();

        this->p1->resetDelta();
        this->p1->spaceship->deactivateBoost();
        lastTime = currentTime;
        this->p1->spaceship->weapon->updateCooldown(deltaTime);
      }
    } else if (this->state == MENU) {
      this->draw();
    }
  }
}

GameWindow::~GameWindow(void) {
  SDL_DestroyWindow(this->window);
  SDL_DestroyRenderer(this->renderer);
  this->asteroids.clear();
  delete this->menu;
  delete this->font;
}