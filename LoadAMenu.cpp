#include "LoadAMenu.h"

//Constructor.
LoadAMenu::LoadAMenu(I_Manager *battleManager , int playerPosition , Menu *menu){

    this->battleManager = battleManager;
    this->playerPosition = playerPosition;
    this->menu = menu;
    this->isExecuted = false;
}

//Destructor.
LoadAMenu::~LoadAMenu(){

    //Default is fine.
}

//Executes the event.
//Pre:  None.
//Post: Returns true if the menu is no longer active on the
//      battleManager menu queue. Otherwise returns false.
bool LoadAMenu::execute(){

    if(!isExecuted){

        battleManager->setCurrPlayer(playerPosition);

        //If the player is dead.
        if(battleManager->currPlayerDead()){
            return true;
        }

        else{
            battleManager->loadMenu(menu);
            isExecuted = true;
            return false;
        }
    }

    //Player turn is not done yet.
    if(!battleManager->emptyMenus())
        return false;  
    
    //Execution is complete.
    else return true;

}