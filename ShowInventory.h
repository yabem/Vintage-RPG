//Displays the player's inventory.

#pragma once
#include "Cutscene.h"
#include "GameManager.h"

class ShowInventory : public Cutscene{

protected:
    
    PlayerEntity *playerEntity;
    GameManager *gameManager;
    bool firstTimeThrough;

public:

    ShowInventory(GameManager *gameManager , PlayerEntity *playerEntity);
    ~ShowInventory();
    bool play(const int pressedKey);
};