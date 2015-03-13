//Initiates the player turn.

#pragma once
#include "I_Event.h"
#include "I_Manager.h"
class Menu;

class PlayerTurn : public I_Event{

private:

    I_Manager *battleManager;
    Menu *menu;
    bool isExecuted;

public:

    PlayerTurn(I_Manager *battleManager , Menu *menu);
    virtual ~PlayerTurn();
    virtual bool execute();
};