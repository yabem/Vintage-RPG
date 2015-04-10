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

    possibleAttacks.push_back("Fire2");
    possibleAttacks.push_back("Rock");
}

//Destructor.
ratAI::~ratAI(){
}

//Attacks a random player.
//Pre:  None.
//Post: Attacks a random player.
void ratAI::executeBattleLogic(){

    int randomPlayer = rand() % listOfEnemies->getSize();
    int randomAttack = rand() % possibleAttacks.size();

    //Player is already dead, choose another.
    if(listOfPlayers->getCharacterSelection(randomPlayer)->isDead()){

        randomPlayer = 0;

        while(listOfPlayers->getCharacterSelection(randomPlayer)->isDead() &&
            randomPlayer < listOfPlayers->getSize()){
            
                randomPlayer++;
        }  
    }  

    //Execute a manipulation from the available abilities.
    characterManipulationStore->executeManipulation(
        initiator , 
        listOfPlayers->getCharacterSelection(randomPlayer) ,
        possibleAttacks[randomAttack]);
}