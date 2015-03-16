
#include "PlayerTurn.h"

//Constructor.
PlayerTurn::PlayerTurn(int playerPosition, I_Manager *battleManager ,
    Menu *menu , TurnTimer *turnTimer){

    this->playerPosition = playerPosition;
    this->battleManager = battleManager;
    this->menu = menu;
    this->turnTimer = turnTimer;
}

//Destructor.
PlayerTurn::~PlayerTurn(){

}

//Executes the player's turn.
//Pre:  The menu is valid.
//Post: Always returns true since this event only executes once..
bool PlayerTurn::execute(){

    LoadAMenu *loadAMenu = new LoadAMenu(battleManager , playerPosition , menu);
    battleManager->loadEvent(loadAMenu);

    //Load the ResetTurnTimer Event.
    ResetTurnTimer *resetTurnTimer = new ResetTurnTimer(turnTimer);
    battleManager->loadEvent(resetTurnTimer);

    return true;
}