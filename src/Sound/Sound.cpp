#include "Sound/Sound.hpp"

Sound::Sound(const char* path){
  if(SDL_LoadWAV(path, &this->wavSpec, &this->wavBuffer, &this->wavLength)==NULL){
    fprintf(stderr, "Could not open %s: %s\n", path, SDL_GetError());
  };
  this->deviceId = SDL_OpenAudioDevice(NULL, 0, &this->wavSpec, NULL, 0);
  this->pause = 1;
}

Sound::~Sound(){
  SDL_CloseAudioDevice(this->deviceId);
  SDL_FreeWAV(this->wavBuffer);
}

void Sound::playPause(){
  int success = SDL_QueueAudio(this->deviceId, this->wavBuffer, this->wavLength);
  if(this->pause>0){
    SDL_PauseAudioDevice(this->deviceId, 0);
    this->pause = 0;
  }
  else{
    SDL_PauseAudioDevice(this->deviceId, 1);
    this->pause = 1;
  }
}