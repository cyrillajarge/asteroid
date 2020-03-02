#ifndef SOUNDS_HPP
#define SOUNDS_HPP

#include <SDL2/SDL.h>
#include <iostream>

class Sound{
  public:
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;
    SDL_AudioDeviceID deviceId;
    int pause;
    
    Sound(const char* path);
    ~Sound();
    void playPause();
};

#endif