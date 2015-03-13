#include "ratAI.h"

//Constuctor.
ratAI::ratAI(CharacterManipulationStore *characterManipulationStore ,
    I_List *listOfPlayers , I_List *listOfEnemies){

    this->characterManipulationStore = characterManipulationStore;
    this->listOfPlayers = listOfPlayers;
    this->listOfEnemies = listOfEnemies;
}

//Destructor.
ratAI::~ratAI(){
}

void ratAI::executeBattleLogic(){

    characterManipulationStore->executeRandomManipulation(
        listOfPlayers->getCharacterSelection(0) ,
        listOfEnemies->getCharacterSelection(0));
}