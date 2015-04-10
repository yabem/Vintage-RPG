#include "Recover.h"

//Default constructor.
Recover::Recover(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    drawRepository = NULL;
    recoveryAmount = 0;
}

//Destructor.
Recover::~Recover(){

    //Deletion is handled by the ImageStore.
}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void Recover::loadCharacters(Character *initiator ,
    Character *receiver){

    this->initiator = initiator;
    this->receiver = receiver;
}
 
//Initiates the recovery amount to teh character.
//Pre:  Both characters have been loaded.
//Post: The initiator's HP increase by the calculated amount.
void Recover::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Determines the amount to recover.
    calculateRecovery();

    //Remove receiver's hitpoints.
    initiator->addToRemainingHP(recoveryAmount);

    loadAnimations();
}

//Loads the animations to the animations vector.
void Recover::loadAnimations(){

    //Creates the text that will display the damage above the receiver.
    MovingText *recovery = new MovingText(font , 10 , 10 , 8 , false);
    MovingText *recoveryStay = new MovingText(font , 10 , 10 , 16 , false);

    //Convert damage to string for display purposes.
    char theRecovery[10];
    _itoa_s(recoveryAmount , theRecovery , 10);

    //Sets the start and end coordinates.
    recovery->initialize(theRecovery , initiator->getX() , initiator->getY() , 
        initiator->getX() , initiator->getY() - 50);
    recoveryStay->initialize(theRecovery , initiator->getX() , initiator->getY() , 
        initiator->getX() , initiator->getY());

    drawRepository->loadAnimation(recovery);
    drawRepository->loadAnimation(recoveryStay); 
}

//Calculates the recovery amount.
void Recover::calculateRecovery(){

    //Get attack and defense for calculation.
    this->recoveryAmount = initiator->getTtlHP() * 0.10;
}
