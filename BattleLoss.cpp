#include "BattleLoss.h"

//Constructor with parameters.
BattleLoss::BattleLoss(AreaMap *currMap , CharacterList *listOfPlayers ,
        CharacterList *listOfEnemies , I_Manager *gameManager , ALLEGRO_FONT *font){

    frameCount = 0;
    mapSwitch = 1;
    this->currMap = currMap;
    this->listOfPlayers =  new CharacterList();
    this->listOfEnemies =  new CharacterList();
    this->gameManager = gameManager;
    this->font = font;

    this->textBox = new TextBox("You have been slain by the enemies. Press SPACE to "
        "close the game." , font);
    //textBox->loadText("You have been slain by the enemies. Press SPACE to "
    //    "close the game.");

    listOfPlayers->resetSelection();
    listOfEnemies->resetSelection();

    for(int i = 0 ; i < listOfPlayers->getSize() ; i++){

        Character *copyOfCharacter = new Character();
        *copyOfCharacter = *listOfPlayers->getCurrSelection();
        this->listOfPlayers->loadChar(copyOfCharacter);
        listOfPlayers->moveSelectionDown();
    }

    for(int i = 0 ; i < listOfEnemies->getSize() ; i++){

        Character *copyOfCharacter = new Character();
        *copyOfCharacter = *listOfEnemies->getCurrSelection();
        this->listOfEnemies->loadChar(copyOfCharacter);
        listOfEnemies->moveSelectionDown();
    }
}

//Destructor.
BattleLoss::~BattleLoss(){

    delete textBox;
}

//Plays the battle victory. The cutscene switches back and forth
//between the current map and a white background.
bool BattleLoss::play(const int pressedKey){
    
    frameCount++;

    Draw::drawArea(*currMap);
    Draw::drawCharListForBattle(this->listOfPlayers);
    Draw::drawCharListForBattle(this->listOfEnemies);
    textBox->draw();

    if(pressedKey == SPACE){

        listOfPlayers->resetSelection();
        for(int i = 0 ; i < listOfPlayers->getSize() ; i++){

            delete listOfPlayers->getCurrSelection();
            listOfPlayers->moveSelectionDown();
        }

        listOfEnemies->resetSelection();
        for(int i = 0 ; i < listOfEnemies->getSize() ; i++){

            delete listOfEnemies->getCurrSelection();
            listOfEnemies->moveSelectionDown();
        }

        gameManager->setEndOfGameLoopToEnd();
        return true;
    }

    else return false;
}