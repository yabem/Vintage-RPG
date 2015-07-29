#include "EarthShatter.h"

//Default constructor.
EarthShatter::EarthShatter(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    drawRepository = NULL;
    damageToReceiver = 0;
}

//Destructor.
EarthShatter::~EarthShatter(){

    //Deletion is handled by the ImageStore.
}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void EarthShatter::loadCharacters(Character *initiator ,
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
void EarthShatter::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Determines the damage to the receiver.
    calculateDamage();

    //Remove receiver's hitpoints.
    receiver->addToRemainingHP(-damageToReceiver);

    loadAnimations();
}

//Loads the animations to the animations vector.
void EarthShatter::loadAnimations(){

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
    MovingCreature *moveUpForAttack = new MovingCreature(initiator , 0);
    MovingCreature *backToStartingPosition = new MovingCreature(initiator , 0);
    
    setInitiatorAttackPosition(initiator , receiver , moveIntoAttackPositionX ,
        moveIntoAttackPositionY);

    positionBeforeAttack->initialize(origPositionX - 208, origPositionY - 88 ,
        moveIntoAttackPositionX, moveIntoAttackPositionY);

    moveUpForAttack->initialize(origPositionX , origPositionY ,
        origPositionX - 208, origPositionY - 88);

    backToStartingPosition->initialize(moveIntoAttackPositionX,
        moveIntoAttackPositionY, origPositionX , origPositionY);

    SetCreatureFacingDirection *originalFacingDirection =
        new SetCreatureFacingDirection(initiator , LEFT);
    SetCreatureFacingDirection *attackFacingDirection =
        new SetCreatureFacingDirection(initiator , UP);

    ChangeCreatureImage *warriorEarthShatter1 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("warriorEarthShatter1"));
    ChangeCreatureImage *warriorEarthShatter2 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("warriorEarthShatter2"));
    ChangeCreatureImage *warriorEarthShatter3 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("warriorEarthShatter3"));
    ChangeCreatureImage *warriorEarthShatter4 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("warriorEarthShatter4"));
    ChangeCreatureImage *warriorEarthShatter5 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("warriorEarthShatter5"));
    ChangeCreatureImage *warriorEarthShatter6 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("warriorEarthShatter6"));
    ChangeCreatureImage *warriorEarthShatter7 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("warriorEarthShatter7"));
    ChangeCreatureImage *warriorEarthShatter8 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("warriorEarthShatter8"));
    ChangeCreatureImage *warriorEarthShatter9 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("warriorEarthShatter9"));

    ChangeCreatureImage *origImage = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("warrior"));

    ChangeCharacterWidth *increaseWidthForAttack = new ChangeCharacterWidth(
        initiator , 240);
    ChangeCharacterWidth *decreaseWidthToOriginalSize = new ChangeCharacterWidth(
        initiator , 32);

    ChangeCharacterHeight *increaseHeightForAttack = new ChangeCharacterHeight(
        initiator , 120);
    ChangeCharacterHeight *decreaseHeightToOriginalSize = new ChangeCharacterHeight(
        initiator , 32);

    DelayInSeconds *delay1 = new DelayInSeconds(.3);
    DelayInSeconds *delay2 = new DelayInSeconds(.2);
    DelayInSeconds *delay3 = new DelayInSeconds(.05);
    DelayInSeconds *delay4 = new DelayInSeconds(.05);
    DelayInSeconds *delay5 = new DelayInSeconds(.05);
    DelayInSeconds *delay6 = new DelayInSeconds(.05);
    DelayInSeconds *delay7 = new DelayInSeconds(.05);
    DelayInSeconds *delay8 = new DelayInSeconds(.05);
    DelayInSeconds *delay9 = new DelayInSeconds(.2);

    SimultaneousAnimations *attackSetup = new SimultaneousAnimations();
    attackSetup->loadAnimation(increaseWidthForAttack);
    attackSetup->loadAnimation(increaseHeightForAttack);
    attackSetup->loadAnimation(attackFacingDirection);
    attackSetup->loadAnimation(warriorEarthShatter1);
    attackSetup->loadAnimation(moveUpForAttack);

    SimultaneousAnimations *resetToOriginalPosition = new SimultaneousAnimations();
    resetToOriginalPosition->loadAnimation(decreaseWidthToOriginalSize);
    resetToOriginalPosition->loadAnimation(decreaseHeightToOriginalSize);
    resetToOriginalPosition->loadAnimation(origImage);
    resetToOriginalPosition->loadAnimation(originalFacingDirection);
    resetToOriginalPosition->loadAnimation(backToStartingPosition);

    //Load all the animations to the animations queue.
    drawRepository->loadAnimation(attackSetup);

    //drawRepository->loadAnimation(positionBeforeAttack);
    drawRepository->loadAnimation(positionBeforeAttack);
    drawRepository->loadAnimation(delay1);
    drawRepository->loadAnimation(warriorEarthShatter2);
    drawRepository->loadAnimation(delay2);
    drawRepository->loadAnimation(warriorEarthShatter3);
    drawRepository->loadAnimation(delay3);
    drawRepository->loadAnimation(warriorEarthShatter4);
    drawRepository->loadAnimation(delay4);
    drawRepository->loadAnimation(warriorEarthShatter5);
    drawRepository->loadAnimation(delay5);
    drawRepository->loadAnimation(warriorEarthShatter6);
    drawRepository->loadAnimation(delay6);
    drawRepository->loadAnimation(warriorEarthShatter7);
    drawRepository->loadAnimation(delay7);
    drawRepository->loadAnimation(warriorEarthShatter8);
    drawRepository->loadAnimation(delay8);
    drawRepository->loadAnimation(warriorEarthShatter9);
    drawRepository->loadAnimation(delay9);
    drawRepository->loadAnimation(damage);
    drawRepository->loadAnimation(damageStay); 

    drawRepository->loadAnimation(resetToOriginalPosition);
}

//Calculates the damage to the receiver.
//Pre:  None.
//Post: The initiator is the Character doing the attacking
//      The receiver is the Character receiving the attack.
//      The imageStore is where the images will be taken from.
void EarthShatter::calculateDamage(){

    damageToReceiver = DamageCalculations::damageWithoutDelay(initiator, receiver);
}

//Sets the draw to spell location.
void EarthShatter::setInitiatorAttackPosition(Character *initiator , 
    Character *receiver , int &moveIntoAttackPositionX ,
    int &moveIntoAttackPositionY){

    int attackImageHeight = 120;

    moveIntoAttackPositionX = receiver->getX();

    moveIntoAttackPositionY = receiver->getY() + receiver->getH() - attackImageHeight;
}