#include "ProcessPlayerInput.h"

void ProcessPlayerInput::processPlayerInput(GameManager *gameManager , PlayerEntity *playerEntity ,
    DrawRepository *drawRepository){

    //Display active quest log.
    if(gameManager->getPressedKey() == L){
        ShowActiveQuestLog *showActiveQuestLog = new 
            ShowActiveQuestLog(gameManager , playerEntity);
        drawRepository->loadCutscene(showActiveQuestLog);
        gameManager->resetPressedKey();
    }

    //Display completed quest log.
    if(gameManager->getPressedKey() == O){
        ShowCompletedQuestLog *showCompletedQuestLog = new 
            ShowCompletedQuestLog(gameManager , playerEntity);
        drawRepository->loadCutscene(showCompletedQuestLog);
        gameManager->resetPressedKey();
    }

    //Display player inventory.
    if(gameManager->getPressedKey() == I){
        ShowInventory *showInvenory= new 
            ShowInventory(gameManager , playerEntity);
        drawRepository->loadCutscene(showInvenory);
        gameManager->resetPressedKey();
    }

    //Display party statuses.
    if(gameManager->getPressedKey() == U){
        ShowPartyStatus *showPartyStatus= new 
            ShowPartyStatus(gameManager , playerEntity);
        drawRepository->loadCutscene(showPartyStatus);
        gameManager->resetPressedKey();
    }
}