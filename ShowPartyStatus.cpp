#include "ShowPartyStatus.h"
    
ShowPartyStatus::ShowPartyStatus(GameManager *gameManager ,
    PlayerEntity *playerEntity){

    this->playerEntity = playerEntity;
    this->gameManager = gameManager;
    this->firstTimeThrough = true;
}

ShowPartyStatus::~ShowPartyStatus(){

}

//Plays the cutscene. Returns false if not done playing, returns true
//when done playing.
bool ShowPartyStatus::play(const int pressedKey){
    
    if(firstTimeThrough){

        playerEntity->updatePartyStatusDisplay();
        firstTimeThrough = false;
    }

    //Animate player.
    gameManager->player->animate();
            
    //Animate the sceneries. 
    gameManager->currMap->animateSceneries();

    //Draw map.
    Draw::drawArea(*gameManager->currMap , *gameManager->player);

    playerEntity->displayPlayerStats();

    if(pressedKey == U){
        return true;
    }

    else return false;
}