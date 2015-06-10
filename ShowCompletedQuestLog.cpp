#include "ShowCompletedQuestLog.h"
    
ShowCompletedQuestLog::ShowCompletedQuestLog(GameManager *gameManager ,
    PlayerEntity *playerEntity){

    this->playerEntity = playerEntity;
    this->gameManager = gameManager;
}

ShowCompletedQuestLog::~ShowCompletedQuestLog(){

}

//Plays the cutscene. Returns false if not done playing, returns true
//when done playing.
bool ShowCompletedQuestLog::play(const int pressedKey){

    //Animate player.
    gameManager->player->animate();
            
    //Animate the sceneries. 
    gameManager->currMap->animateSceneries();

    //Draw map.
    Draw::drawArea(*gameManager->currMap , *gameManager->player);

    playerEntity->displayCompletedQuestsInQuestLog();

    if(pressedKey == C){
        return true;
    }

    else return false;
}