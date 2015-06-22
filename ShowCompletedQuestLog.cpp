#include "ShowCompletedQuestLog.h"
    
ShowCompletedQuestLog::ShowCompletedQuestLog(GameManager *gameManager ,
    PlayerEntity *playerEntity){

    this->playerEntity = playerEntity;
    this->gameManager = gameManager;
    this->firstTimeThrough = true;
}

ShowCompletedQuestLog::~ShowCompletedQuestLog(){

}

//Plays the cutscene. Returns false if not done playing, returns true
//when done playing.
bool ShowCompletedQuestLog::play(const int pressedKey){

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

    playerEntity->displayCompletedQuestsInQuestLog();

    if(pressedKey == O){
        return true;
    }

    else return false;
}