#include "UpdatePlayersHP.h"

//Constructor.
UpdatePlayersHP::UpdatePlayersHP(I_Manager *battleManager){

    this->battleManager = battleManager;
}

//Destructor.
UpdatePlayersHP::~UpdatePlayersHP(){

}

//Updates the player's hitpoints.
//Pre:  None.
//Post: Executes only once so always returns true.
bool UpdatePlayersHP::execute(){

    battleManager->updateFloatingTexts();
    return true;
}