#pragma once
#include "Cutscene.h"
#include "MusicBox.h"
#include "GameManager.h"

class PlayMusic: public Cutscene{

private:
    GameManager *gameManager;
    std::string songName;

public:
    PlayMusic(GameManager *gameManager , std::string songName);
    virtual ~PlayMusic();
    virtual bool play(const int pressedKey);
};