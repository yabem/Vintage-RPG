#include "GameInitialization.h"

void GameInitialization::loadAllEnemyModels(BattleManager *battleManager ,
    ImageStore *imageStore){

    battleManager->loadEnemyModel(imageStore->getBitMap("Rat"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Wolf"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Soldier"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Ice Bull"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Blob King"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Guardian"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Demon"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Carrot Rat"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Walrus"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Goo Cube"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Ice Cube"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Fire Cube"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Shield Skeleton"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Wererat"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Cactus"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Oldman Axe"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Mushroom Man"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Zombie"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Baby Blob"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Sheep"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Kungfoo Dog"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Fanged Fox"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Ninja Fox"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Red Reaper"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Spider"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Spider Egg"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Spider Web"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Tentacle Mage"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Echidna"));
    battleManager->loadEnemyModel(imageStore->getBitMap("Umgar The World Destroyer"));
}

void GameInitialization::loadIntro(GameManager *gameManager , 
    DrawRepository *drawRepository , FontStore *fontStore , ImageStore *imageStore){

    Intro *theIntro = new Intro(fontStore->getFont("default") , imageStore); 
    theIntro->loadBackground();
    Instruct *theInstruct = new Instruct(fontStore->getFont("default") , gameManager);

    drawRepository->loadCutscene(theIntro);   
    drawRepository->loadCutscene(theInstruct);
}