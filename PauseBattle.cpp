#include "PauseBattle.h"

//Constructor.
PauseBattle::PauseBattle(I_Manager *i_Manager){

    this->battleManager = i_Manager;
}

//Pauses the battleManager.
bool PauseBattle::play(){

    battleManager->pauseBattle();
    return true;
}