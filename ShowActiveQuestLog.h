//Displays the player's active quests.

#pragma once
#include "Cutscene.h"
#include "GameManager.h"

class ShowActiveQuestLog : public Cutscene{

protected:
    
    PlayerEntity *playerEntity;
    GameManager *gameManager;
    bool firstTimeThrough;

public:

    ShowActiveQuestLog(GameManager *gameManager , PlayerEntity *playerEntity);
    ~ShowActiveQuestLog();
    bool play(const int pressedKey);
};