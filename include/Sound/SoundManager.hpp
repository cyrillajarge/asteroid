#ifndef SOUNDMANAGER_HPP
#define SOUNDMANAGER_HPP

#include <iostream>

#include "Sound/Sound.hpp"

class SoundManager{
  public:
    Sound* backgroundMusic;
    Sound* shoot;
    bool soundFX = false;

    SoundManager(char* bgmusic, char* shoot);
    void playPauseMusic();
    void activateSoundFX();
    void playPauseShootSound();
    ~SoundManager();
};

#endif