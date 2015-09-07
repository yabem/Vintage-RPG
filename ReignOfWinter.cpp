#include "ReignOfWinter.h"

//Default constructor.
ReignOfWinter::ReignOfWinter(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    drawRepository = NULL;
    damageToReceiver = 0;
}

//Destructor.
ReignOfWinter::~ReignOfWinter(){

    //Deletion is handled by the ImageStore.
}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void ReignOfWinter::loadCharacters(Character *initiator ,
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
void ReignOfWinter::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Determines the damage to the receiver.
    calculateDamage();

    //Remove receiver's hitpoints.
    receiver->addToRemainingHP(-damageToReceiver);

    loadAnimations();
}

//Loads the animations to the animations vector.
void ReignOfWinter::loadAnimations(){

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

    MovingCreature *moveUpForAttack = new MovingCreature(initiator , 0);
    MovingCreature *positionBeforeAttack = new MovingCreature(initiator , 10);
    MovingCreature *backToStartingPosition = new MovingCreature(initiator , 0);
    
    setInitiatorAttackPosition(initiator , receiver , moveIntoAttackPositionX ,
        moveIntoAttackPositionY);

    moveUpForAttack->initialize(origPositionX , origPositionY ,
        origPositionX - 280, origPositionY - 267);

    positionBeforeAttack->initialize(origPositionX - 278, origPositionY - 267 ,
        moveIntoAttackPositionX, moveIntoAttackPositionY);

    backToStartingPosition->initialize(moveIntoAttackPositionX,
        moveIntoAttackPositionY, origPositionX , origPositionY);

    SetCreatureFacingDirection *originalFacingDirection =
        new SetCreatureFacingDirection(initiator , LEFT);
    SetCreatureFacingDirection *attackFacingDirection =
        new SetCreatureFacingDirection(initiator , UP);

    ChangeCreatureImage *mageReignOfWinter1 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageReignOfWinter1"));
    ChangeCreatureImage *mageReignOfWinter2 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageReignOfWinter2"));
    ChangeCreatureImage *mageReignOfWinter3 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageReignOfWinter3"));
    ChangeCreatureImage *mageReignOfWinter4 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageReignOfWinter4"));
    ChangeCreatureImage *mageReignOfWinter5 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageReignOfWinter5"));
    ChangeCreatureImage *mageReignOfWinter6 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageReignOfWinter6"));
    ChangeCreatureImage *mageReignOfWinter7 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageReignOfWinter7"));
    ChangeCreatureImage *mageReignOfWinter8 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageReignOfWinter8"));
    ChangeCreatureImage *mageReignOfWinter9 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageReignOfWinter9"));
    ChangeCreatureImage *mageReignOfWinter10 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageReignOfWinter10"));
    ChangeCreatureImage *mageReignOfWinter11 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageReignOfWinter11"));

    ChangeCreatureImage *origImage = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mage"));

    ChangeCharacterWidth *increaseWidthForAttack = new ChangeCharacterWidth(
        initiator , 400);
    ChangeCharacterWidth *decreaseWidthToOriginalSize = new ChangeCharacterWidth(
        initiator , 32);

    ChangeCharacterHeight *increaseHeightForAttack = new ChangeCharacterHeight(
        initiator , 300);
    ChangeCharacterHeight *decreaseHeightToOriginalSize = new ChangeCharacterHeight(
        initiator , 32);

    DelayInSeconds *delay1 = new DelayInSeconds(.3);
    DelayInSeconds *delay2 = new DelayInSeconds(.5);
    DelayInSeconds *delay3 = new DelayInSeconds(.03);
    DelayInSeconds *delay4 = new DelayInSeconds(.2);
    DelayInSeconds *delay5 = new DelayInSeconds(.03);
    DelayInSeconds *delay6 = new DelayInSeconds(.2);
    DelayInSeconds *delay7 = new DelayInSeconds(.03);
    DelayInSeconds *delay8 = new DelayInSeconds(.1);
    DelayInSeconds *delay9 = new DelayInSeconds(.3);
    DelayInSeconds *delay10 = new DelayInSeconds(.03);
    DelayInSeconds *delay11 = new DelayInSeconds(.5);

    SimultaneousAnimations *attackSetup = new SimultaneousAnimations();
    attackSetup->loadAnimation(increaseWidthForAttack);
    attackSetup->loadAnimation(increaseHeightForAttack);
    attackSetup->loadAnimation(attackFacingDirection);
    attackSetup->loadAnimation(mageReignOfWinter1);
    attackSetup->loadAnimation(moveUpForAttack);

    SimultaneousAnimations *resetToOriginalPosition = new SimultaneousAnimations();
    resetToOriginalPosition->loadAnimation(decreaseWidthToOriginalSize);
    resetToOriginalPosition->loadAnimation(decreaseHeightToOriginalSize);
    resetToOriginalPosition->loadAnimation(origImage);
    resetToOriginalPosition->loadAnimation(originalFacingDirection);
    resetToOriginalPosition->loadAnimation(backToStartingPosition);

    //Load all the animations to the animations queue.
    drawRepository->loadAnimation(attackSetup);

    drawRepository->loadAnimation(positionBeforeAttack);
    drawRepository->loadAnimation(delay1);
    drawRepository->loadAnimation(mageReignOfWinter2);
    drawRepository->loadAnimation(delay2);
    drawRepository->loadAnimation(mageReignOfWinter3);
    drawRepository->loadAnimation(delay3);
    drawRepository->loadAnimation(mageReignOfWinter4);
    drawRepository->loadAnimation(delay4);
    drawRepository->loadAnimation(mageReignOfWinter5);
    drawRepository->loadAnimation(delay5);
    drawRepository->loadAnimation(mageReignOfWinter6);
    drawRepository->loadAnimation(delay6);
    drawRepository->loadAnimation(mageReignOfWinter7);
    drawRepository->loadAnimation(delay7);
    drawRepository->loadAnimation(mageReignOfWinter8);
    drawRepository->loadAnimation(delay8);
    drawRepository->loadAnimation(mageReignOfWinter9);
    drawRepository->loadAnimation(delay9);
    drawRepository->loadAnimation(mageReignOfWinter10);
    drawRepository->loadAnimation(delay10);
    drawRepository->loadAnimation(mageReignOfWinter11);
    drawRepository->loadAnimation(delay11);
    drawRepository->loadAnimation(damage);
    drawRepository->loadAnimation(damageStay); 

    drawRepository->loadAnimation(resetToOriginalPosition);
}

//Calculates the damage to the receiver.
//Pre:  None.
//Post: The initiator is the Character doing the attacking
//      The receiver is the Character receiving the attack.
//      The imageStore is where the images will be taken from.
void ReignOfWinter::calculateDamage(){

    damageToReceiver = DamageCalculations::damageWithDelayMgc(
        initiator, receiver , 6.5 , 2);
}

//Sets the draw to spell location.
void ReignOfWinter::setInitiatorAttackPosition(Character *initiator , 
    Character *receiver , int &moveIntoAttackPositionX ,
    int &moveIntoAttackPositionY){

    int attackImageHeight = 300;

    moveIntoAttackPositionX = receiver->getX() - 75;

    moveIntoAttackPositionY = receiver->getY() + receiver->getH() - attackImageHeight;
}