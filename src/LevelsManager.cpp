#include "LevelsManager.hpp"
#include "UI/PlainText.hpp"

LevelsManager::LevelsManager(){
  this->status = 1;
  this->nb_asteroids = 6;
  this->speed = 2.0f;
  this->message = false;
}

void LevelsManager::nextLevel(){
  this->status++;
  this->nb_asteroids += 2;
  this->speed += 0.5f;
}

void LevelsManager::resetLevels(){
  this->status = 1;
  this->nb_asteroids = 6;
  this->speed = 2.0f;
  this->message = false;
}

void LevelsManager::drawMessage(SDL_Renderer *renderer, int height, int width){
  if(this->message){
    PlainText* message = new PlainText("LEVEL "+ std::to_string(this->status), {400,400});
    message->center(width, height);
    message->draw(renderer);
  }
}
