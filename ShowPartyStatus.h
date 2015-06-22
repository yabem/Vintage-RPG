//Displays the status of every character in the party.

#pragma once
#include "Cutscene.h"
#include "GameManager.h"

class ShowPartyStatus : public Cutscene{

protected:
    
    PlayerEntity *playerEntity;
    GameManager *gameManager;
    bool firstTimeThrough;

public:

    ShowPartyStatus(GameManager *gameManager , PlayerEntity *playerEntity);
    ~ShowPartyStatus();
    bool play(const int pressedKey);
};