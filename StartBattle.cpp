#include "StartBattle.h"

StartBattle::StartBattle(BattleManager *battleManager , std::vector<int> enemyList , 
        std::vector<int> enemyLevels){

    this->battleManager = battleManager;
    this->enemyList = enemyList;
    this->enemyLevels = enemyLevels;
}

StartBattle::~StartBattle(){

}

//Starts the battle and always returns true since the cutscene is only
//executed once.
bool StartBattle::play(const int pressedKey){

    battleManager->initializeBattle(enemyList , enemyLevels);
    return true;
}
