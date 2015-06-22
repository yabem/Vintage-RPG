#include "ShowInventory.h"
    
ShowInventory::ShowInventory(GameManager *gameManager ,
    PlayerEntity *playerEntity){

    this->playerEntity = playerEntity;
    this->gameManager = gameManager;
    this->firstTimeThrough = true;
}

ShowInventory::~ShowInventory(){

}

//Plays the cutscene. Returns false if not done playing, returns true
//when done playing.
bool ShowInventory::play(const int pressedKey){

    if(firstTimeThrough){

        playerEntity->getPlayerInventory()->updateInventoryDisplay();
        firstTimeThrough = false;
    }

    //Animate player.
    gameManager->player->animate();
            
    //Animate the sceneries. 
    gameManager->currMap->animateSceneries();

    //Draw map.
    Draw::drawArea(*gameManager->currMap , *gameManager->player);

    playerEntity->getPlayerInventory()->displayInventory();

    if(pressedKey == I){
        return true;
    }

    else return false;
}