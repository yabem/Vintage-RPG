#include "ratAI.h"

//Constuctor.
ratAI::ratAI(Character *initiator ,
    CharacterManipulationStore *characterManipulationStore ,
    I_List *listOfPlayers , I_List *listOfEnemies ,
    DrawRepository *drawRepository){

    this->initiator = initiator;
    this->characterManipulationStore = characterManipulationStore;
    this->listOfPlayers = listOfPlayers;
    this->listOfEnemies = listOfEnemies;
    this->drawRepository = drawRepository;

    possibleAttacks.push_back("Fire1");
    possibleAttacks.push_back("Rock");
}

//Destructor.
ratAI::~ratAI(){
}

//Attacks a random player.
//Pre:  None.
//Post: Attacks a random player.
void ratAI::executeBattleLogic(){

    int randomNum = rand() % listOfEnemies->getSize();
    int randomAttack = rand() % possibleAttacks.size();

    characterManipulationStore->executeManipulation(
        initiator , 
        listOfPlayers->getCharacterSelection(randomNum) ,
        possibleAttacks[randomAttack]);
}