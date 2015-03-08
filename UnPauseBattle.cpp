#include "UnPauseBattle.h"

//Constructor.
UnPauseBattle::UnPauseBattle(I_Manager *i_Manager){

    this->battleManager = i_Manager;
}

//Pauses the battleManager.
bool UnPauseBattle::play(){

    battleManager->unPauseBattle();
    return true;
}