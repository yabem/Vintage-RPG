
#include "PlayerTurn.h"

//Constructor.
PlayerTurn::PlayerTurn(I_Manager *battleManager , Menu *menu){

    this->battleManager = battleManager;
    this->menu = menu;
    this->isExecuted = false;
}

//Destructor.
PlayerTurn::~PlayerTurn(){

    //delete menu;
}

//Executes the player's turn.
//Pre:  The menu is valid.
//Post: Returns false if not done. Returns true if done.
bool PlayerTurn::execute(){

    //Execute for the first time.
    if(!isExecuted){
        battleManager->loadMenu(menu);
        isExecuted = true;
        return false;
    }

    //Enemy turn is not done yet.
    else if(!battleManager->emptyMenus())
        return false;  
    
    //Execution is complete.
    else return true;
}