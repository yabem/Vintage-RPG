#include "KnifeBarrage.h"

//Default constructor.
KnifeBarrage::KnifeBarrage(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    drawRepository = NULL;
    damageToReceiver = 0;
}

//Destructor.
KnifeBarrage::~KnifeBarrage(){

    //Deletion is handled by the ImageStore.
}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void KnifeBarrage::loadCharacters(Character *initiator ,
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
void KnifeBarrage::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Determines the damage to the receiver.
    calculateDamage();

    //Remove receiver's hitpoints.
    receiver->addToRemainingHP(-damageToReceiver);

    loadAnimations();
}

//Loads the animations to the animations vector.
void KnifeBarrage::loadAnimations(){

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

    positionBeforeAttack->initialize(origPositionX - 208, origPositionY - 8 ,
        moveIntoAttackPositionX, moveIntoAttackPositionY);

    moveUpForAttack->initialize(origPositionX , origPositionY ,
        origPositionX - 208, origPositionY - 8);

    backToStartingPosition->initialize(moveIntoAttackPositionX,
        moveIntoAttackPositionY, origPositionX , origPositionY);

    SetCreatureFacingDirection *originalFacingDirection =
        new SetCreatureFacingDirection(initiator , LEFT);
    SetCreatureFacingDirection *attackFacingDirection =
        new SetCreatureFacingDirection(initiator , UP);

    ChangeCreatureImage *thiefKnifeBarrage1 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefKnifeBarrage1"));
    ChangeCreatureImage *thiefKnifeBarrage2 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefKnifeBarrage2"));
    ChangeCreatureImage *thiefKnifeBarrage3 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefKnifeBarrage3"));
    ChangeCreatureImage *thiefKnifeBarrage4 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefKnifeBarrage4"));
    ChangeCreatureImage *thiefKnifeBarrage5 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefKnifeBarrage5"));
    ChangeCreatureImage *thiefKnifeBarrage6 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefKnifeBarrage6"));
    ChangeCreatureImage *thiefKnifeBarrage7 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefKnifeBarrage7"));
    ChangeCreatureImage *thiefKnifeBarrage8 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefKnifeBarrage8"));

    ChangeCreatureImage *origImage = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thief"));

    ChangeCharacterWidth *increaseWidthForAttack = new ChangeCharacterWidth(
        initiator , 160);
    ChangeCharacterWidth *decreaseWidthToOriginalSize = new ChangeCharacterWidth(
        initiator , 32);

    ChangeCharacterHeight *increaseHeightForAttack = new ChangeCharacterHeight(
        initiator , 40);
    ChangeCharacterHeight *decreaseHeightToOriginalSize = new ChangeCharacterHeight(
        initiator , 32);

    DelayInSeconds *delay1 = new DelayInSeconds(.4);
    DelayInSeconds *delay2 = new DelayInSeconds(.1);
    DelayInSeconds *delay3 = new DelayInSeconds(.1);
    DelayInSeconds *delay4 = new DelayInSeconds(.1);
    DelayInSeconds *delay5 = new DelayInSeconds(.1);
    DelayInSeconds *delay6 = new DelayInSeconds(.1);
    DelayInSeconds *delay7 = new DelayInSeconds(.1);
    DelayInSeconds *delay8 = new DelayInSeconds(.4);

    SimultaneousAnimations *attackSetup = new SimultaneousAnimations();
    attackSetup->loadAnimation(increaseWidthForAttack);
    attackSetup->loadAnimation(increaseHeightForAttack);
    attackSetup->loadAnimation(attackFacingDirection);
    attackSetup->loadAnimation(thiefKnifeBarrage1);
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
    drawRepository->loadAnimation(thiefKnifeBarrage2);
    drawRepository->loadAnimation(delay2);
    drawRepository->loadAnimation(thiefKnifeBarrage3);
    drawRepository->loadAnimation(delay3);
    drawRepository->loadAnimation(thiefKnifeBarrage4);
    drawRepository->loadAnimation(delay4);
    drawRepository->loadAnimation(thiefKnifeBarrage5);
    drawRepository->loadAnimation(delay5);
    drawRepository->loadAnimation(thiefKnifeBarrage6);
    drawRepository->loadAnimation(delay6);
    drawRepository->loadAnimation(thiefKnifeBarrage7);
    drawRepository->loadAnimation(delay7);
    drawRepository->loadAnimation(thiefKnifeBarrage8);
    drawRepository->loadAnimation(delay8);
    drawRepository->loadAnimation(damage);
    drawRepository->loadAnimation(damageStay); 

    drawRepository->loadAnimation(resetToOriginalPosition);
}

//Calculates the damage to the receiver.
//Pre:  None.
//Post: The initiator is the Character doing the attacking
//      The receiver is the Character receiving the attack.
//      The imageStore is where the images will be taken from.
void KnifeBarrage::calculateDamage(){

    damageToReceiver = DamageCalculations::damageWithoutDelay(initiator, receiver);
}

//Sets the draw to spell location.
void KnifeBarrage::setInitiatorAttackPosition(Character *initiator , 
    Character *receiver , int &moveIntoAttackPositionX ,
    int &moveIntoAttackPositionY){

    int attackImageHeight = 40;

    moveIntoAttackPositionX = receiver->getX();

    moveIntoAttackPositionY = receiver->getY() + receiver->getH() - attackImageHeight;
}