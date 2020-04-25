#include "LevelsManager.hpp"
#include "UI/PlainText.hpp"

LevelsManager::LevelsManager(std::string path){
  this->config = this->readConfigFile(path);
  this->status = 1;
  this->nb_asteroids = 6;
  this->speed = 2.0f;
  this->message = false;
}

std::vector<std::pair<int, double>> LevelsManager::readConfigFile(std::string path){
  std::vector<std::pair<int, double>> levels;
  std::ifstream f(path);
  std::string bs;
  std::string sep = " ";
  while (std::getline(f, bs)) {
    size_t pos = bs.find_first_of(sep);
    size_t pos2 = bs.find_last_of(sep);
    int naster = std::stoi(bs.substr(pos+1,pos2-1));
    double speed = std::stod(bs.substr(pos2+1,bs.length()));
    std::cout << speed << std::endl;
    levels.push_back(std::make_pair(naster, speed));
  }
  return levels;
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
