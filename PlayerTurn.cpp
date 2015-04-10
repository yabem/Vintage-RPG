
#include "PlayerTurn.h"

//Constructor.
PlayerTurn::PlayerTurn(int playerPosition, I_Manager *battleManager ,
    Menu *menu , TurnTimer *turnTimer , I_List *listOfEnemies ,
    DrawRepository *drawRepository){

    this->playerPosition = playerPosition;
    this->battleManager = battleManager;
    this->menu = menu;
    this->turnTimer = turnTimer;
    this->listOfEnemies = listOfEnemies;
    this->drawRepository = drawRepository;
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

    //Check if any enemy died after the player's turn.
    for(int i = 0 ; i < listOfEnemies->getSize() ; i++){

        CheckForDeadEnemy *checkForDeadEnemy = new CheckForDeadEnemy(
            listOfEnemies->getCharacterSelection(i) , drawRepository ,
            battleManager);

        battleManager->loadEvent(checkForDeadEnemy);
    }

    //Load the ResetTurnTimer Event.
    ResetTurnTimer *resetTurnTimer = new ResetTurnTimer(turnTimer);
    battleManager->loadEvent(resetTurnTimer);

    //Load the UpdatePlayersHP event.
    UpdatePlayersHP *updatePlayersHP = new UpdatePlayersHP(battleManager);
    battleManager->loadEvent(updatePlayersHP);

    return true;
}