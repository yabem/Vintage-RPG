//Initiates the player turn.

#pragma once
#include "I_Event.h"
#include "I_Manager.h"
#include "ResetTurnTimer.h"
#include "LoadAMenu.h"
#include "CheckForDeadEnemy.h"
#include "I_List.h"
class DrawRepository;
class Menu;
class TurnTimer;

class PlayerTurn : public I_Event{

private:

    int playerPosition; //The player's position.
    I_Manager *battleManager;
    Menu *menu;
    TurnTimer *turnTimer;
    I_List *listOfEnemies;  //All the enemies.
    DrawRepository *drawRepository;

public:

    //Constructor.
    PlayerTurn(int playerPosition , I_Manager *battleManager , Menu *menu ,
        TurnTimer *turnTimer , I_List *listOfEnemies , 
        DrawRepository *drawRepository);
    
    //Destructor.
    virtual ~PlayerTurn();

    //Executes all the necessar subevents.
    void initiateSubEvents();

    //Executes the PlayerTurn.
    virtual bool execute();
};