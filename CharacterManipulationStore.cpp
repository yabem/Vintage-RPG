#include "CharacterManipulationStore.h"

//No parameter constructor.
CharacterManipulationStore::CharacterManipulationStore(){

}

//Destructor.
CharacterManipulationStore::~CharacterManipulationStore(){

    std::map<std::string , CharacterManipulation*>::iterator iter =
        characterManipulations.begin();

    while(iter != characterManipulations.end()){

        delete (iter->second);
        characterManipulations.erase(iter);
        iter = characterManipulations.begin();
    }
}

//Loads the image store.
void CharacterManipulationStore::loadImageStore(ImageStore *imageStore){

    this->imageStore = imageStore;
}

//Loads the gameManager.
void CharacterManipulationStore::loadGameManager(GameManager *gameManager){

    this->gameManager = gameManager;
}

/*
//Generates and executes the manipulation.
void CharacterManipulationStore::generateManipulation(Character *initiator ,
    Character *receiver , std::string manipulation){
    
        
    switch(){

        CharacterAttack characterAttack;
        characterAttack.loadAttack(initiator , receiver ,
            imageStore , font18);
        characterAttack.execute();
    }
    
}
*/

//Load a single CharacterManipulation to the store.
//Pre:  The charManip is valid.
//Post: The key (name) and value (CharacterManipulation) are loaded
//      into the characterManipulations map.
void CharacterManipulationStore::loadManipulation(std::string name , 
    CharacterManipulation *charManip){

    //Don't add anything if pointer is NULL.
    if(charManip == NULL || name == "")
        return;

    else characterManipulations.insert
        (std::pair<std::string , CharacterManipulation*>(name , charManip));
}

//Loads all of the default CharacterManipulation.
//Pre:  None.
//Post: Loads all the CharacterManipulations into the 
//      characterManipulations map.
void CharacterManipulationStore::loadAllDefaultManipulations(){

    CharacterManipulation *charManip = new CharacterManipulation;
    charManip->initialize(NULL , NULL , imageStore , fontStore , 
        gameManager);
    loadManipulation("attack" , charManip);
}

//Retrieves a pointer to the CharacterManipulation.
//Pre:  None.
//Post: Returns a CharacterManipulation pointer.
CharacterManipulation* CharacterManipulationStore::getManip
    (std::string charManip){

    //Create iterator for testing if the element exists.
    std::map<std::string , CharacterManipulation*>::iterator iter =
        characterManipulations.begin();

    iter = characterManipulations.find(charManip);

    if(iter == characterManipulations.end()){

        //Element not found, return CharacterManipulation.
        return NULL;    
    }

    else return iter->second;
}

//Executes the manipulation.
//Pre:  None.
//Post: Executes the manipulation based off of the receiver.
void CharacterManipulationStore::executeManipulation(Character *initiator ,
    Character *receiver , std::string manipulation){

    CharacterManipulation *charManip = getManip(manipulation);
    charManip->loadCharacters(initiator , receiver);
}

