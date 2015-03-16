#include "BattleLoss.h"

//Constructor with parameters.
BattleLoss::BattleLoss(AreaMap *currMap , CharacterList *listOfPlayers ,
        CharacterList *listOfEnemies , I_Manager *gameManager){

    frameCount = 0;
    mapSwitch = 1;
    this->currMap = currMap;
    this->listOfPlayers = listOfPlayers;
    this->listOfEnemies = listOfEnemies;
    this->gameManager = gameManager;

    textBox.loadText("You have been slain by the enemies. Press SPACE to "
        "close the game.");
}

//Destructor.
BattleLoss::~BattleLoss(){

}

//Plays the battle victory. The cutscene switches back and forth
//between the current map and a white background.
bool BattleLoss::play(const int pressedKey){
    
    frameCount++;

    Draw::drawArea(*currMap);
    Draw::drawCharListForBattle(listOfPlayers);
    Draw::drawCharListForBattle(listOfEnemies);
    textBox.draw();

    if(pressedKey == SPACE){

        gameManager->setEndOfGameLoopToEnd();
        return true;
    }

    else return false;
}