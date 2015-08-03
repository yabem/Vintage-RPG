#include "ShadeOfTheCrescent.h"

//Default constructor.
ShadeOfTheCrescent::ShadeOfTheCrescent(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    drawRepository = NULL;
    damageToReceiver = 0;
}

//Destructor.
ShadeOfTheCrescent::~ShadeOfTheCrescent(){

    //Deletion is handled by the ImageStore.
}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void ShadeOfTheCrescent::loadCharacters(Character *initiator ,
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
void ShadeOfTheCrescent::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Determines the damage to the receiver.
    calculateDamage();

    //Remove receiver's hitpoints.
    receiver->addToRemainingHP(-damageToReceiver);

    loadAnimations();
}

//Loads the animations to the animations vector.
void ShadeOfTheCrescent::loadAnimations(){

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
        origPositionX - 368, origPositionY - 48);

    positionBeforeAttack->initialize(origPositionX - 368, origPositionY - 48 ,
        moveIntoAttackPositionX, moveIntoAttackPositionY);

    backToStartingPosition->initialize(moveIntoAttackPositionX,
        moveIntoAttackPositionY, origPositionX , origPositionY);

    SetCreatureFacingDirection *originalFacingDirection =
        new SetCreatureFacingDirection(initiator , LEFT);
    SetCreatureFacingDirection *attackFacingDirection =
        new SetCreatureFacingDirection(initiator , UP);

    ChangeCreatureImage *thiefMutilatingStrikes1 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes1"));
    ChangeCreatureImage *thiefMutilatingStrikes2 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes2"));
    ChangeCreatureImage *thiefMutilatingStrikes3 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes3"));
    ChangeCreatureImage *thiefMutilatingStrikes4 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes4"));
    ChangeCreatureImage *thiefMutilatingStrikes5 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes5"));
    ChangeCreatureImage *thiefMutilatingStrikes6 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes6"));
    ChangeCreatureImage *thiefMutilatingStrikes7 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes7"));
    ChangeCreatureImage *thiefMutilatingStrikes8 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes8"));
    ChangeCreatureImage *thiefMutilatingStrikes9 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes9"));
    ChangeCreatureImage *thiefMutilatingStrikes10 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes10"));
    ChangeCreatureImage *thiefMutilatingStrikes11 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes11"));
    ChangeCreatureImage *thiefMutilatingStrikes12 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes12"));
    ChangeCreatureImage *thiefMutilatingStrikes13 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes13"));
    ChangeCreatureImage *thiefMutilatingStrikes14 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes14"));
    ChangeCreatureImage *thiefMutilatingStrikes15 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes15"));
    ChangeCreatureImage *thiefMutilatingStrikes16 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes16"));
    ChangeCreatureImage *thiefMutilatingStrikes17 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes17"));
    ChangeCreatureImage *thiefMutilatingStrikes18 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes18"));
    ChangeCreatureImage *thiefMutilatingStrikes19 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes19"));
    ChangeCreatureImage *thiefMutilatingStrikes20 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefMutilatingStrikes20"));


    ChangeCreatureImage *origImage = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thief"));

    ChangeCharacterWidth *increaseWidthForAttack = new ChangeCharacterWidth(
        initiator , 400);
    ChangeCharacterWidth *decreaseWidthToOriginalSize = new ChangeCharacterWidth(
        initiator , 32);

    ChangeCharacterHeight *increaseHeightForAttack = new ChangeCharacterHeight(
        initiator , 80);
    ChangeCharacterHeight *decreaseHeightToOriginalSize = new ChangeCharacterHeight(
        initiator , 32);

    DelayInSeconds *delay1 = new DelayInSeconds(.4);
    DelayInSeconds *delay2 = new DelayInSeconds(.2);
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
    DelayInSeconds *delay13 = new DelayInSeconds(.4);
    DelayInSeconds *delay14 = new DelayInSeconds(.4);
    DelayInSeconds *delay15 = new DelayInSeconds(.15);
    DelayInSeconds *delay16 = new DelayInSeconds(.15);
    DelayInSeconds *delay17 = new DelayInSeconds(.15);
    DelayInSeconds *delay18 = new DelayInSeconds(.15);
    DelayInSeconds *delay19 = new DelayInSeconds(.15);
    DelayInSeconds *delay20 = new DelayInSeconds(.4);

    SimultaneousAnimations *attackSetup = new SimultaneousAnimations();
    attackSetup->loadAnimation(increaseWidthForAttack);
    attackSetup->loadAnimation(increaseHeightForAttack);
    attackSetup->loadAnimation(attackFacingDirection);
    attackSetup->loadAnimation(thiefMutilatingStrikes1);
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
    drawRepository->loadAnimation(thiefMutilatingStrikes2);
    drawRepository->loadAnimation(delay2);
    drawRepository->loadAnimation(thiefMutilatingStrikes3);
    drawRepository->loadAnimation(delay3);
    drawRepository->loadAnimation(thiefMutilatingStrikes4);
    drawRepository->loadAnimation(delay4);
    drawRepository->loadAnimation(thiefMutilatingStrikes5);
    drawRepository->loadAnimation(delay5);
    drawRepository->loadAnimation(thiefMutilatingStrikes6);
    drawRepository->loadAnimation(delay6);
    drawRepository->loadAnimation(thiefMutilatingStrikes7);
    drawRepository->loadAnimation(delay7);
    drawRepository->loadAnimation(thiefMutilatingStrikes8);
    drawRepository->loadAnimation(delay8);
    drawRepository->loadAnimation(thiefMutilatingStrikes9);
    drawRepository->loadAnimation(delay9);
    drawRepository->loadAnimation(thiefMutilatingStrikes10);
    drawRepository->loadAnimation(delay10);
    drawRepository->loadAnimation(thiefMutilatingStrikes11);
    drawRepository->loadAnimation(delay11);
    drawRepository->loadAnimation(thiefMutilatingStrikes12);
    drawRepository->loadAnimation(delay12);
    drawRepository->loadAnimation(thiefMutilatingStrikes13);
    drawRepository->loadAnimation(delay13);
    drawRepository->loadAnimation(thiefMutilatingStrikes14);
    drawRepository->loadAnimation(delay14);
    drawRepository->loadAnimation(thiefMutilatingStrikes15);
    drawRepository->loadAnimation(delay15);
    drawRepository->loadAnimation(thiefMutilatingStrikes16);
    drawRepository->loadAnimation(delay16);
    drawRepository->loadAnimation(thiefMutilatingStrikes17);
    drawRepository->loadAnimation(delay17);
    drawRepository->loadAnimation(thiefMutilatingStrikes18);
    drawRepository->loadAnimation(delay18);
    drawRepository->loadAnimation(thiefMutilatingStrikes19);
    drawRepository->loadAnimation(delay19);
    drawRepository->loadAnimation(thiefMutilatingStrikes20);
    drawRepository->loadAnimation(delay20);

    drawRepository->loadAnimation(damage);
    drawRepository->loadAnimation(damageStay); 

    drawRepository->loadAnimation(resetToOriginalPosition);
}

//Calculates the damage to the receiver.
//Pre:  None.
//Post: The initiator is the Character doing the attacking
//      The receiver is the Character receiving the attack.
//      The imageStore is where the images will be taken from.
void ShadeOfTheCrescent::calculateDamage(){

    damageToReceiver = DamageCalculations::damageWithoutDelay(initiator, receiver);
}

//Sets the draw to spell location.
void ShadeOfTheCrescent::setInitiatorAttackPosition(Character *initiator , 
    Character *receiver , int &moveIntoAttackPositionX ,
    int &moveIntoAttackPositionY){

    int attackImageHeight = 80;

    moveIntoAttackPositionX = receiver->getX() - 59;

    moveIntoAttackPositionY = receiver->getY() + receiver->getH() - attackImageHeight;
}