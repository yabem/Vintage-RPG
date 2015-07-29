#include "Dagger.h"

//Default constructor.
Dagger::Dagger(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    drawRepository = NULL;
    damageToReceiver = 0;
}

//Destructor.
Dagger::~Dagger(){

    //Deletion is handled by the ImageStore.
}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void Dagger::loadCharacters(Character *initiator ,
    Character *receiver){

    this->initiator = initiator;
    this->receiver = receiver;
}
 
//Initiates the attack action between the two Characters.
//Pre:  Both characters have been loaded.
//Post: The initiator's attack is checked against the
//      receiver's defense. The attack that is leftover
//      after the defense is subtracted is then reduced
//      from the receiver's hitpoints. If the HP are reduced
//      to 0 or below, the Character will be dead.
void Dagger::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Determines the damage to the receiver.
    calculateDamage();

    //Remove receiver's hitpoints.
    receiver->addToRemainingHP(-damageToReceiver);

    loadAnimations();
}

//Loads the animations to the animations vector.
void Dagger::loadAnimations(){

    //Creates the text that will display the damage above the receiver.
    MovingText *damage = new MovingText(font , 10 , 10 , 8 , false);
    MovingText *damageStay = new MovingText(font , 10 , 10 , 16 , false);

    //Convert damage to string for display purposes.
    std::string theDamage = Conversion::convertIntToString(damageToReceiver);

    //Sets the start and end coordinates.
    damage->initialize(theDamage , receiver->getX() , receiver->getY() , 
        receiver->getX() , receiver->getY() - 50);
    damageStay->initialize(theDamage , receiver->getX() , receiver->getY() , 
        receiver->getX() , receiver->getY());
    
    int origPositionX = initiator->getX();
    int origPositionY = initiator->getY();
    int moveIntoAttackPositionX = 0;
    int moveIntoAttackPositionY = 0;

    MovingCreature *positionBeforeAttack = new MovingCreature(initiator , 10);
    MovingCreature *moveUpForAttack = new MovingCreature(initiator , 1);
    MovingCreature *backToStartingPosition = new MovingCreature(initiator , 0);
    
    setInitiatorAttackPosition(initiator , receiver , moveIntoAttackPositionX ,
        moveIntoAttackPositionY);

    positionBeforeAttack->initialize(origPositionX , origPositionY ,
        moveIntoAttackPositionX, moveIntoAttackPositionY);

    moveUpForAttack->initialize(moveIntoAttackPositionX , moveIntoAttackPositionY ,
        moveIntoAttackPositionX - 19, moveIntoAttackPositionY);

    backToStartingPosition->initialize(moveIntoAttackPositionX,
        moveIntoAttackPositionY, origPositionX , origPositionY);

    SetCreatureFacingDirection *originalFacingDirection =
        new SetCreatureFacingDirection(initiator , LEFT);
    SetCreatureFacingDirection *attackFacingDirection =
        new SetCreatureFacingDirection(initiator , UP);

    ChangeCreatureImage *mageAttackPart1 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefAttackPart1"));
    ChangeCreatureImage *mageAttackPart2 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefAttackPart2"));
    ChangeCreatureImage *origImage = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thief"));

    ChangeCharacterWidth *increaseWidthForAttack = new ChangeCharacterWidth(
        initiator , 35);
    ChangeCharacterHeight *increaseHeightForAttack = new ChangeCharacterHeight(
        initiator , 36);
    ChangeCharacterWidth *decreaseWidthToOriginalSize = new ChangeCharacterWidth(
        initiator , 32);
    ChangeCharacterHeight *decreaseHeightToOriginalSize = new ChangeCharacterHeight(
        initiator , 32);

    DelayInSeconds *delayAttackPart1 = new DelayInSeconds(.1);
    DelayInSeconds *delayAttackPart2 = new DelayInSeconds(.2);

    SimultaneousAnimations *attackSetup = new SimultaneousAnimations();
    attackSetup->loadAnimation(increaseWidthForAttack);
    attackSetup->loadAnimation(increaseHeightForAttack);
    attackSetup->loadAnimation(attackFacingDirection);
    attackSetup->loadAnimation(mageAttackPart1);

    SimultaneousAnimations *resetToOriginalPosition = new SimultaneousAnimations();
    resetToOriginalPosition->loadAnimation(decreaseWidthToOriginalSize);
    resetToOriginalPosition->loadAnimation(decreaseHeightToOriginalSize);
    resetToOriginalPosition->loadAnimation(origImage);
    resetToOriginalPosition->loadAnimation(originalFacingDirection);
    resetToOriginalPosition->loadAnimation(backToStartingPosition);

    //Load all the animations to the animations queue.
    drawRepository->loadAnimation(attackSetup);

    drawRepository->loadAnimation(positionBeforeAttack);
    drawRepository->loadAnimation(moveUpForAttack);
    drawRepository->loadAnimation(delayAttackPart1);
    drawRepository->loadAnimation(mageAttackPart2);
    drawRepository->loadAnimation(delayAttackPart2);
    drawRepository->loadAnimation(damage);
    drawRepository->loadAnimation(damageStay); 

    drawRepository->loadAnimation(resetToOriginalPosition);
}

//Calculates the damage to the receiver.
//Pre:  None.
//Post: The initiator is the Character doing the attacking
//      The receiver is the Character receiving the attack.
//      The imageStore is where the images will be taken from.
void Dagger::calculateDamage(){

    damageToReceiver = DamageCalculations::damageWithoutDelay(initiator, receiver);
}

//Sets the draw to spell location.
void Dagger::setInitiatorAttackPosition(Character *initiator , 
    Character *receiver , int &moveIntoAttackPositionX ,
    int &moveIntoAttackPositionY){

    moveIntoAttackPositionX = receiver->getX() + receiver->getW();

    //Receiver is taller than initiator.
    if(receiver->getH() > initiator->getH()){

        moveIntoAttackPositionY = receiver->getY() +
            ((receiver->getH() - initiator->getH()) / 2);
    }

    //Initiator is taller than receiver.
    else{
        moveIntoAttackPositionY = receiver->getY() -
            ((initiator->getH() - receiver->getH()) / 2);
    }
}