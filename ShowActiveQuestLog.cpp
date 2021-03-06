#include "ShowActiveQuestLog.h"
    
ShowActiveQuestLog::ShowActiveQuestLog(GameManager *gameManager ,
    PlayerEntity *playerEntity){

    this->playerEntity = playerEntity;
    this->gameManager = gameManager;
    this->firstTimeThrough = true;
}

ShowActiveQuestLog::~ShowActiveQuestLog(){

}

//Plays the cutscene. Returns false if not done playing, returns true
//when done playing.
bool ShowActiveQuestLog::play(const int pressedKey){

    if(firstTimeThrough){

        playerEntity->updateQuestDisplays();
        firstTimeThrough = false;
    }

    //Animate player.
    gameManager->player->animate();
            
    //Animate the sceneries. 
    gameManager->currMap->animateSceneries();

    //Draw map.
    Draw::drawArea(*gameManager->currMap , *gameManager->player);

    playerEntity->displayActiveQuestsInQuestLog();

    if(pressedKey == L){
        return true;
    }

    else return false;
}