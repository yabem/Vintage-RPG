#include "RemoveTangible.h"

RemoveTangible::RemoveTangible(GameManager *gameManager ,
    std::string identifierNameToRemove){

    this->gameManager = gameManager;
    this->identifierNameToRemove = identifierNameToRemove;
}

RemoveTangible::~RemoveTangible(){

}

//Removes the specified Tangible from the Tangibles list.
//Pre:  None.
//Post: Removes the Tangible if it is in the list. If the Tangible does
//      not exist, nothing happens.
bool RemoveTangible::play(const int pressedKey){

    //Animate player.
    gameManager->player->animate();
            
    //Animate the sceneries. 
    gameManager->currMap->animateSceneries();

    //Draw map.
    Draw::drawArea(*gameManager->currMap , *gameManager->player);

    gameManager->removeTangibleFromCurrMap(this->identifierNameToRemove);
    return true;
}
