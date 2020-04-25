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
#include <future>

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

  // // Setting up game entities
  this->initPlayers();

  // Setting up UI
  this->font = new Font({255, 255, 255, 255});
  UIComponent::font = this->font;
  this->menu = std::make_unique<Menu>(this->font);
  this->initMenu();

  this->end_menu = std::make_unique<Menu>(this->font);
  this->initEndMenu();

  this->scoreboard_menu = std::make_unique<Menu>(this->font);
  this->initScoreboardMenu();

  this->scoreboard = std::make_unique<Scoreboard>();

  // Setting up level manager
  this->levels_manager = std::make_unique<LevelsManager>();

  this->state = MENU;
  dynamic_cast<Clickable *>(this->menu->components["play"])
      ->handler = [this]() {
    this->initPlayers();
    this->players[0]->name =
        dynamic_cast<TextInput *>(this->menu->components["gamertag"])->input;
    this->end_menu->components["message"]->label =
        "LMAO u ded " + this->players[0]->name + "!!";
    this->end_menu->components["message"]->centerHorizontally(this->width);
    this->initGame();
  };

  dynamic_cast<Clickable *>(this->menu->components["scoreboard"])
    ->handler = [this]() {
      this->previous_state = this->state;
      this->state = SCOREBOARD_MENU;
  };

  dynamic_cast<Clickable *>(this->menu->components["coop"])
  ->handler = [this]() {
    dynamic_cast<Checkbox *>(this->menu->components["coop"])->checked = !dynamic_cast<Checkbox *>(this->menu->components["coop"])->checked;
    this->coop_mode = !this->coop_mode;
    if(this->menu->components["gamertag"]->label == "Enter Squad name: "){
      this->menu->components["gamertag"]->label = "Enter Gamertag: ";
    }
    else{
      this->menu->components["gamertag"]->label = "Enter Squad name: ";
    }
  };

  dynamic_cast<Clickable *>(this->end_menu->components["playa"])->handler =
      [this]() { this->initGame(); };
  
  dynamic_cast<Clickable *>(this->end_menu->components["scoreboard"])->handler =
      [this]() { 
        this->previous_state = this->state;
        this->state = SCOREBOARD_MENU; 
      };
  
  dynamic_cast<Clickable *>(this->scoreboard_menu->components["return"])->handler =
      [this]() { 
        this->state = this->previous_state;
      };
}

void GameWindow::initMenu() {
  this->menu->addPlainText("title", "ASTEROID", {200, 200});
  this->menu->components["title"]->center(width, height);
  this->menu->components["title"]->moveY(-150);

  this->menu->addButton("play", "PLAY", {200, 200});
  this->menu->components["play"]->border = true;
  this->menu->components["play"]->border_color = {0, 255, 0, 255};
  this->menu->components["play"]->center(width, height);
  this->menu->components["play"]->moveY(-50);

  this->menu->addCheckbox("coop", "Co-op", {200,200});
  this->menu->components["coop"]->center(width, height);

  this->menu->addButton("scoreboard", "Show scoreboard", {200,200});
  this->menu->components["scoreboard"]->border = true;
  this->menu->components["scoreboard"]->border_color = {0, 0, 255, 255};
  this->menu->components["scoreboard"]->center(width, height);
  this->menu->components["scoreboard"]->moveY(50);

  this->menu->addTextInput("gamertag", "Enter Gamertag: ", {400, 400});
  this->menu->components["gamertag"]->center(width, height);
  this->menu->components["gamertag"]->moveY(150);
}

void GameWindow::initEndMenu() {
  this->end_menu->addPlainText("message", "LMAO u ded!!", {200, 200});
  this->end_menu->components["message"]->center(width, height);
  this->end_menu->components["message"]->moveY(-200);

  this->end_menu->addPlainText(
      "score", "Your score : " + std::to_string(this->players[0]->score),
      {400, 400});
  this->end_menu->components["score"]->center(width, height);
  this->end_menu->components["score"]->moveY(-75);

  this->end_menu->addPlainText(
      "level", "You reached level " + std::to_string(this->players[0]->level) + "!",
      {400, 400});
  this->end_menu->components["level"]->center(width, height);

  this->end_menu->addButton("scoreboard", "Show scoreboard",{200,200});
  this->end_menu->components["scoreboard"]->border = true;
  this->end_menu->components["scoreboard"]->border_color = {0, 0, 255, 255};
  this->end_menu->components["scoreboard"]->center(width, height);
  this->end_menu->components["scoreboard"]->moveY(75);

  this->end_menu->addButton("playa", "Play Again", {200, 200});
  this->end_menu->components["playa"]->center(width, height);
  this->end_menu->components["playa"]->moveY(200);
  this->end_menu->components["playa"]->border = true;
  this->end_menu->components["playa"]->border_color = {0, 255, 0, 255};
}

void GameWindow::initScoreboardMenu(){
  this->scoreboard_menu->addPlainText("title", "SCOREBOARD", {0, 100});
  this->scoreboard_menu->components["title"]->centerHorizontally(width);

  this->scoreboard_menu->addButton("return", "< RETURN", {10, 35});
  this->scoreboard_menu->components["return"]->border = true;
  this->scoreboard_menu->components["return"]->border_color = {255, 0, 0, 255};
}


void GameWindow::initAsteroids(int number) {
  this->asteroids.clear();
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

void GameWindow::initPlayers(){
  // Setting up game entities
  this->players[0] = std::make_unique<Player>(MAPPING_P1);
  if(coop_mode) this->players[1] = std::make_unique<Player>(MAPPING_P2);
}

void GameWindow::initGame() {
  if (this->state != GAME) {
    this->players[0]->score = 0;
    this->players[0]->level = 1;
    this->players[0]->alive = true;
    glm::vec2 position = glm::vec2(this->width / 2.0f, this->height / 2.0f);
    this->players[0]->initShip(position, 20);
    if(coop_mode){
      this->players[1]->score = 0;
      this->players[1]->level = 1;
      position = glm::vec2(this->width / 2.0f, this->height / 2.0f);
      this->players[1]->initShip(position, 20); 
      this->players[1]->alive = true; 
    }

    this->state = GAME;
    this->levels_manager->resetLevels();
    this->initAsteroids(this->levels_manager->nb_asteroids);
  }
}

void GameWindow::endGame() {
  int total_score = (coop_mode)? this->players[0]->score + this->players[1]->score : this->players[0]->score;
  this->end_menu->components["message"]->label =
      "LMAO u ded " + this->players[0]->name + "!!";
  this->end_menu->components["message"]->centerHorizontally(width);
  this->end_menu->components["score"]->label =
      "Your score : " + std::to_string(total_score);
  this->end_menu->components["score"]->centerHorizontally(width);
  this->end_menu->components["level"]->label =
      "You reached level " + std::to_string(this->players[0]->level) + "!";
  this->end_menu->components["level"]->centerHorizontally(width);
  this->players[0]->spaceship->invincible = true;
  if(coop_mode){
    this->players[1]->spaceship->invincible = true;
  }
  this->state = END_MENU;
  this->asteroids.clear();
  this->scoreboard->saveScore(this->players[0]->name, total_score);
}

void GameWindow::nextLevel(){
  this->levels_manager->nextLevel();
  this->players[0]->level++;
  if(coop_mode){
    this->players[1]->level++;
  }
  this->initAsteroids(this->levels_manager->nb_asteroids);
}

void GameWindow::updateAsteroids() {
  if(this->asteroids.size()==0){
    this->nextLevel();
  }
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

    this->asteroids[i]->center += this->levels_manager->speed * this->asteroids[i]->direction;
  }
}

void GameWindow::updateScore(int player, int level) {
  switch (level) {
  case 2:
    this->players[player]->score += 20;
    break;
  case 1:
    this->players[player]->score += 50;
    break;
  case 0:
    this->players[player]->score += 100;
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
  } else if (this->state == END_MENU) {
    this->end_menu->draw(this->renderer);
  } else if(this->state == SCOREBOARD_MENU){
    this->scoreboard->updateMenu(this->scoreboard_menu, width);
    this->scoreboard_menu->draw(this->renderer);
  } else {
    // Draw level message
    this->font->color = {0,0,255,255};
    this->levels_manager->drawMessage(renderer, this->height, this->width);
    this->font->color = {255,255,255,255};

    int eos;
    // Draw score
    eos = this->font->drawText(this->renderer, "Score :", 50, 50);
    std::string score = std::to_string(this->players[0]->score);
    this->font->drawText(this->renderer, score, eos + 20, 50);

    // Draw Gamertag
    this->font->color = {0, 255, 0, 255};
    int gamertag_length = this->font->getWidth(this->players[0]->name);
    int offset = 100;
    this->font->drawText(this->renderer, this->players[0]->name,
                         this->width / 2 - gamertag_length / 2 - offset, 50);

    this->font->color = {255, 255, 255, 255};

    int cd_y_offset = 50;
    
    for (auto const &p : this->players) {
      if (!p || !p->alive)
        continue;
      eos = this->font->drawText(this->renderer, "Special CD :", 700, cd_y_offset);
      this->font->drawText(this->renderer,
                          p->spaceship->weapon->getCDStr(),
                          eos + 20, cd_y_offset);
      cd_y_offset += 50;
      p->spaceship->draw(this->renderer);
    }

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);

    for (size_t i = 0; i < this->asteroids.size(); i++) {
      this->asteroids[i]->draw(this->renderer);
    }

    this->particleManager->drawParticles(this->renderer);
  }
  // Render the rect to the screen
  SDL_RenderPresent(renderer);
}

void GameWindow::computeAsteroids(int player) {
  static auto gen_float = alea_generator(-1.0f, 1.0f);
  std::vector<int> collided = this->players[player]->spaceship->weapon->collided(this->asteroids);

  for (int inter : collided) {
    glm::vec2 aster_pos = this->asteroids[inter]->center;
    int ar = this->asteroids[inter]->averageray;
    int nr = this->asteroids[inter]->nrays;
    int lev = this->asteroids[inter]->level;

    this->updateScore(player, lev);

    this->asteroids.erase(this->asteroids.begin() + inter);
    for (int i = 0; i < 10; i++) {
      float speedx = gen_float();
      float speedy = gen_float();
      this->particleManager->addParticle(new LifeParticle(
          glm::vec4(0, 255, 0, 255), aster_pos, glm::vec2(speedx, speedy), 50));
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
}

void GameWindow::processPlayer(int num_player, int current_time) {
  if (num_player > 1 || (num_player == 1 && !this->players[num_player]) || !this->players[num_player]->alive) {
    return;
  }
  // Process inputs
  this->players[num_player]->input_manager->process(current_time);
  // Compute weapon collisions
  this->computeAsteroids(num_player);
  // Compute spaceship collisions
  if (!this->players[num_player]->spaceship->invincible &&
      this->players[num_player]->spaceship->intersectsAsteroid(this->asteroids)) {
    this->players[num_player]->alive = false;
  }
  // Update spaceship position
  this->players[num_player]->spaceship->update(this->players[num_player]->getDelta(), this->width, this->height);
}

void GameWindow::mainLoop(void) {
  int deltaTime = 0, lastTime = 0, currentTime = 0, invincibleTime = 0, levelMessageTime = 0;
  int currentLevel = this->levels_manager->status;
  SDL_Event windowEvent;
  while (this->state != STOPPED) {
    if (SDL_PollEvent(&windowEvent)) {
      switch (windowEvent.type) {
      case SDL_QUIT:
        this->state = STOPPED;
        break;
      case SDL_MOUSEBUTTONDOWN:
        if (this->state == MENU) {
          for (std::pair<std::string, UIComponent *> _comp :
               this->menu->components) {
            if (Clickable *comp = dynamic_cast<Clickable *>(_comp.second)) {
              if (comp->isIn(windowEvent.button.x, windowEvent.button.y)) {
                comp->handler();
              }
            }
          }
        } else if (this->state == END_MENU) {
          for (std::pair<std::string, UIComponent *> _comp :
               this->end_menu->components) {
            if (Clickable *comp = dynamic_cast<Clickable *>(_comp.second)) {
              if (comp->isIn(windowEvent.button.x, windowEvent.button.y)) {
                comp->handler();
              }
            }
          }
        } else if (this->state == SCOREBOARD_MENU) {
          for (std::pair<std::string, UIComponent *> _comp :
               this->scoreboard_menu->components) {
            if (Clickable *comp = dynamic_cast<Clickable *>(_comp.second)) {
              if (comp->isIn(windowEvent.button.x, windowEvent.button.y)) {
                comp->handler();
              }
            }
          }
        }
        break;
      case SDL_TEXTINPUT:
        if (this->state == MENU) {
          dynamic_cast<TextInput *>(this->menu->components["gamertag"])
              ->addLetter(windowEvent);
          this->menu->components["gamertag"]->centerHorizontally(width);
        }
        break;
      case SDL_KEYDOWN:
        if (this->state == MENU) {
          if (windowEvent.key.keysym.sym == SDLK_BACKSPACE) {
            dynamic_cast<TextInput *>(this->menu->components["gamertag"])
                ->removeLetter(windowEvent);
            this->menu->components["gamertag"]->centerHorizontally(width);
          }
          if (windowEvent.key.keysym.sym == SDLK_RETURN) {
            this->initPlayers();
            this->players[0]->name =
                dynamic_cast<TextInput *>(this->menu->components["gamertag"])
                    ->input;
            this->end_menu->components["message"]->label =
                "LMAO u ded" + this->players[0]->name + "!!";
            this->end_menu->components["message"]->centerHorizontally(width);
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

      if(currentLevel != this->levels_manager->status){
        levelMessageTime = 0;
        invincibleTime = 0;
        currentLevel = this->levels_manager->status;
      }

      deltaTime = currentTime - lastTime;
      invincibleTime += currentTime - lastTime;
      levelMessageTime += currentTime - lastTime;
      if(invincibleTime < 2000000){
        this->players[0]->spaceship->invincible = true;
        if(coop_mode){
          this->players[1]->spaceship->invincible = true;
        }
      } else {
        this->players[0]->spaceship->invincible = false;
        if(coop_mode){
          this->players[1]->spaceship->invincible = false;
        }
      }
      (levelMessageTime < 5000000)? this->levels_manager->message = true: this->levels_manager->message = false;
      if (deltaTime > 30) /* Si 30 ms se sont écoulées */
      {
        
        auto f =std::async(&GameWindow::processPlayer, this, 1, currentTime);
        this->processPlayer(0, currentTime);
        f.get();
        
        if (!this->players[0]->alive) {
          if (!this->players[1] || !this->players[1]->alive) {
            this->endGame();
          }
        }

        this->updateAsteroids();
        this->particleManager->updateParticles();
        this->draw();

        for (auto const &p : this->players) {
          if (!p)
            continue;
          p->resetDelta();
          p->spaceship->deactivateBoost();
          p->spaceship->weapon->updateCooldown(deltaTime);
        }
        lastTime = currentTime;
      }
    } else if (this->state == MENU || this->state == END_MENU || this->state == SCOREBOARD_MENU) {
      invincibleTime = 0;
      levelMessageTime = 0;
      this->draw();
    }
  }
}

GameWindow::~GameWindow(void) {
  SDL_DestroyWindow(this->window);
  SDL_DestroyRenderer(this->renderer);
  this->asteroids.clear();
  delete this->font;
}