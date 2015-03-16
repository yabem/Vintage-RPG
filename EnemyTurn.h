//Creates an event that iniates a turn by the enemy.

#pragma once
#include "I_Event.h"
#include "I_AI.h"
#include "I_Manager.h"
#include "ratAI.h"
#include "Character.h"
#include "ResetTurnTimer.h"
#include "DrawRepository.h"
#include "ProcessAI.h"
#include "CheckForDeadPlayer.h"
class TurnTimer;

class EnemyTurn : public I_Event{

private:
    
    //The AI that will be processed.
    I_AI *i_AI;

    //The turn of the enemy.
    Character *enemy;
    
    //Used to load animations.
    DrawRepository *drawRepository;

    //Used to execute the action.
    CharacterManipulationStore *characterManipulationStore;
    I_List *listOfPlayers;  //All the players.
    I_List *listOfEnemies;  //All the enemies.
    I_Manager *battleManager;   //Used to load events.
    TurnTimer *turnTimer; //The timer to reset after the enemy turn.
    bool isExecuted;    //Flag if the logic has been executed.

public:

    //Constructor
    EnemyTurn(Character *enemy ,
        DrawRepository *drawRepository ,
        CharacterManipulationStore *characterManipulationStore ,
        I_List *listOfPlayers , 
        I_List *listOfEnemies ,
        I_Manager *battleManager ,
        TurnTimer *turnTimer);

    //Destructor
    virtual ~EnemyTurn();
    
    //Executes the event.
    virtual bool execute();
};