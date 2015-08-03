#include "ChainLightning.h"

//Default constructor.
ChainLightning::ChainLightning(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    drawRepository = NULL;
    damageToReceiver = 0;
}

//Destructor.
ChainLightning::~ChainLightning(){

    //Deletion is handled by the ImageStore.
}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void ChainLightning::loadCharacters(Character *initiator ,
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
void ChainLightning::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Determines the damage to the receiver.
    calculateDamage();

    //Remove receiver's hitpoints.
    receiver->addToRemainingHP(-damageToReceiver);

    loadAnimations();
}

//Loads the animations to the animations vector.
void ChainLightning::loadAnimations(){

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
        origPositionX - 378, origPositionY - 105);

    positionBeforeAttack->initialize(origPositionX - 378, origPositionY - 105 ,
        moveIntoAttackPositionX, moveIntoAttackPositionY);

    backToStartingPosition->initialize(moveIntoAttackPositionX,
        moveIntoAttackPositionY, origPositionX , origPositionY);

    SetCreatureFacingDirection *originalFacingDirection =
        new SetCreatureFacingDirection(initiator , LEFT);
    SetCreatureFacingDirection *attackFacingDirection =
        new SetCreatureFacingDirection(initiator , UP);

    ChangeCreatureImage *mageChainLightning1 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageChainLightning1"));
    ChangeCreatureImage *mageChainLightning2 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageChainLightning2"));
    ChangeCreatureImage *mageChainLightning3 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageChainLightning3"));
    ChangeCreatureImage *mageChainLightning4 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageChainLightning4"));
    ChangeCreatureImage *mageChainLightning5 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageChainLightning5"));
    ChangeCreatureImage *mageChainLightning6 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageChainLightning6"));
    ChangeCreatureImage *mageChainLightning7 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageChainLightning7"));
    ChangeCreatureImage *mageChainLightning8 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageChainLightning8"));
    ChangeCreatureImage *mageChainLightning9 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageChainLightning9"));
    ChangeCreatureImage *mageChainLightning10 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageChainLightning10"));
    ChangeCreatureImage *mageChainLightning11 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageChainLightning11"));
    ChangeCreatureImage *mageChainLightning12 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageChainLightning12"));

    ChangeCreatureImage *origImage = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mage"));

    ChangeCharacterWidth *increaseWidthForAttack = new ChangeCharacterWidth(
        initiator , 500);
    ChangeCharacterWidth *decreaseWidthToOriginalSize = new ChangeCharacterWidth(
        initiator , 32);

    ChangeCharacterHeight *increaseHeightForAttack = new ChangeCharacterHeight(
        initiator , 250);
    ChangeCharacterHeight *decreaseHeightToOriginalSize = new ChangeCharacterHeight(
        initiator , 32);

    DelayInSeconds *delay1 = new DelayInSeconds(.2);
    DelayInSeconds *delay2 = new DelayInSeconds(.1);
    DelayInSeconds *delay3 = new DelayInSeconds(.1);
    DelayInSeconds *delay4 = new DelayInSeconds(.1);
    DelayInSeconds *delay5 = new DelayInSeconds(.1);
    DelayInSeconds *delay6 = new DelayInSeconds(.1);
    DelayInSeconds *delay7 = new DelayInSeconds(.1);
    DelayInSeconds *delay8 = new DelayInSeconds(.1);
    DelayInSeconds *delay9 = new DelayInSeconds(.1);
    DelayInSeconds *delay10 = new DelayInSeconds(.1);
    DelayInSeconds *delay11 = new DelayInSeconds(.1);
    DelayInSeconds *delay12 = new DelayInSeconds(.1);

    SimultaneousAnimations *attackSetup = new SimultaneousAnimations();
    attackSetup->loadAnimation(increaseWidthForAttack);
    attackSetup->loadAnimation(increaseHeightForAttack);
    attackSetup->loadAnimation(attackFacingDirection);
    attackSetup->loadAnimation(mageChainLightning1);
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
    drawRepository->loadAnimation(mageChainLightning2);
    drawRepository->loadAnimation(delay2);
    drawRepository->loadAnimation(mageChainLightning3);
    drawRepository->loadAnimation(delay3);
    drawRepository->loadAnimation(mageChainLightning4);
    drawRepository->loadAnimation(delay4);
    drawRepository->loadAnimation(mageChainLightning5);
    drawRepository->loadAnimation(delay5);
    drawRepository->loadAnimation(mageChainLightning6);
    drawRepository->loadAnimation(delay6);
    drawRepository->loadAnimation(mageChainLightning7);
    drawRepository->loadAnimation(delay7);
    drawRepository->loadAnimation(mageChainLightning8);
    drawRepository->loadAnimation(delay8);
    drawRepository->loadAnimation(mageChainLightning9);
    drawRepository->loadAnimation(delay9);
    drawRepository->loadAnimation(mageChainLightning10);
    drawRepository->loadAnimation(delay10);
    drawRepository->loadAnimation(mageChainLightning11);
    drawRepository->loadAnimation(delay11);
    drawRepository->loadAnimation(mageChainLightning12);
    drawRepository->loadAnimation(delay12);
    drawRepository->loadAnimation(damage);
    drawRepository->loadAnimation(damageStay); 

    drawRepository->loadAnimation(resetToOriginalPosition);
}

//Calculates the damage to the receiver.
//Pre:  None.
//Post: The initiator is the Character doing the attacking
//      The receiver is the Character receiving the attack.
//      The imageStore is where the images will be taken from.
void ChainLightning::calculateDamage(){

    damageToReceiver = DamageCalculations::damageWithoutDelay(initiator, receiver);
}

//Sets the draw to spell location.
void ChainLightning::setInitiatorAttackPosition(Character *initiator , 
    Character *receiver , int &moveIntoAttackPositionX ,
    int &moveIntoAttackPositionY){

    int attackImageHeight = 137;

    moveIntoAttackPositionX = receiver->getX();

    moveIntoAttackPositionY = receiver->getY() + receiver->getH() - attackImageHeight;
}