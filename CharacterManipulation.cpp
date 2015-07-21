#include "CharacterManipulation.h"


//Default constructor.
CharacterManipulation::CharacterManipulation(){
    
}

//Destructor.
CharacterManipulation::~CharacterManipulation(){

}

//Sets the character information.
void CharacterManipulation::initialize(Character *initiator , 
    Character *receiver , ImageStore *imageStore , 
    FontStore *fontStore , DrawRepository *drawRepository,
    I_Manager *i_Manager){

     this->initiator = initiator;
    this->receiver = receiver;
    this->imageStore = imageStore;
    this->font = fontStore->getFont("default");
    this->drawRepository = drawRepository;
    this->battleManager = i_Manager;
}

//Loads the Characters.
void CharacterManipulation::loadCharacters(Character *initiator ,
    Character *receiver){

}

//Sets the damage.
void CharacterManipulation::setDamage(){

}

//Loads a delay to the Character
void CharacterManipulation::loadDelay(){

}

//Executes the manipulation.
void CharacterManipulation::execute(){

}