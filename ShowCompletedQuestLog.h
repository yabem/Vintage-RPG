//Displays the player's completed quests.

#pragma once
#include "Cutscene.h"
#include "GameManager.h"

class ShowCompletedQuestLog : public Cutscene{

protected:
    
    PlayerEntity *playerEntity;
    GameManager *gameManager;

public:

    ShowCompletedQuestLog(GameManager *gameManager , PlayerEntity *playerEntity);
    ~ShowCompletedQuestLog();
    bool play(const int pressedKey);
};