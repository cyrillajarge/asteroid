#include "LevelsManager.hpp"
#include "UI/PlainText.hpp"

LevelsManager::LevelsManager(std::string path){
  this->config = this->readConfigFile(path);
  this->status = 0;
  this->message = false;
}

std::vector<std::pair<int, float>> LevelsManager::readConfigFile(std::string path){
  std::vector<std::pair<int, float>> levels;
  std::ifstream f(path);
  std::string bs;
  std::string sep = ":";
  while (std::getline(f, bs)) {
    size_t pos = bs.find_first_of(sep);
    size_t pos2 = bs.find_last_of(sep);
    int naster = std::stoi(bs.substr(pos+1,pos2-1));
    float speed = std::stoi(bs.substr(pos2+1,bs.length()))/10.0;
    levels.push_back(std::make_pair(naster, speed));
  }
  return levels;
}

void LevelsManager::nextLevel(){
  this->status++;
  if(this->status>4){
    config.push_back(std::make_pair(config[this->status-1].first+1, config[this->status-1].second+0.5));
  }
}

void LevelsManager::resetLevels(){
  this->status = 0;
  this->message = false;
}

void LevelsManager::drawMessage(SDL_Renderer *renderer, int height, int width){
  if(this->message){
    PlainText* message = new PlainText("LEVEL "+ std::to_string(this->status), {400,400});
    message->center(width, height);
    message->draw(renderer);
  }
}
