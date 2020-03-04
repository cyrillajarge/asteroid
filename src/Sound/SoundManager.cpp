#include "Sound/SoundManager.hpp"

SoundManager::SoundManager(char* bgmusic, char* shoot){
  this->backgroundMusic = new Sound(bgmusic);
  this->shoot = new Sound(shoot);
}

void SoundManager::playPauseMusic(){
  this->backgroundMusic->playPause();
}

void SoundManager::activateSoundFX(){
  this->soundFX = !this->soundFX;
}

void SoundManager::playPauseShootSound(){
  if(this->soundFX){
    this->shoot->playPause();
  }
}

SoundManager::~SoundManager(){
  delete this->backgroundMusic;
  delete this->shoot;
}