#include "I_Manager.h"

I_Manager::~I_Manager(){}

void I_Manager::switchVariablesToMap(){}

void I_Manager::saveAreaMapVariables(){}

void I_Manager::pauseBattle(){}

void I_Manager::unPauseBattle(){}

bool I_Manager::battlePaused(){return false;}

void I_Manager::setCurrPlayer(int position){}

void I_Manager::setCurrEnemy(int position){}

void I_Manager::generatePlayers(CharacterList *characterList , 
        int maxNumberPlayers){}

void I_Manager::loadMenu(Menu *menu){}

void I_Manager::loadEvent(I_Event *i_Event){}

CharacterManipulationStore* I_Manager::getCharManipStore(){return NULL;}

DrawRepository* I_Manager::getDrawRepository(){return NULL;}

CharacterList* I_Manager::getEnemiesList(){return NULL;}

I_List* I_Manager::getPlayersList(){return NULL;}

bool I_Manager::emptyMenus(){return false;}

Character* I_Manager::getCurrEnemy(){return NULL;}

int I_Manager::getPressedKey() const{return 0;}

void I_Manager::setPressedKeyToInactive(){}

void I_Manager::setEndOfGameLoopToEnd(){}

void I_Manager::deleteCurrEnemy(){}

void I_Manager::loadReward(I_Reward *i_Reward){}

void I_Manager::loadBackpack(Backpack *backpack){}

Backpack* I_Manager::getBackpack(){ return NULL;}

void I_Manager::updateFloatingTexts(){}
    
void I_Manager::drawFloatingTexts(){}
   
bool I_Manager::currPlayerDead(){return false;}

void I_Manager::addToDefeatedEnemyList(std::string defeatedEnemy){}