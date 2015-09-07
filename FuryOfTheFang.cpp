#include "FuryOfTheFang.h"

//Default constructor.
FuryOfTheFang::FuryOfTheFang(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    drawRepository = NULL;
    damageToReceiver = 0;
}

//Destructor.
FuryOfTheFang::~FuryOfTheFang(){

    //Deletion is handled by the ImageStore.
}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void FuryOfTheFang::loadCharacters(Character *initiator ,
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
void FuryOfTheFang::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Determines the damage to the receiver.
    calculateDamage();

    //Remove receiver's hitpoints.
    receiver->addToRemainingHP(-damageToReceiver);

    loadAnimations();
}

//Loads the animations to the animations vector.
void FuryOfTheFang::loadAnimations(){

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
        moveIntoAttackPositionX - 39, moveIntoAttackPositionY);

    backToStartingPosition->initialize(moveIntoAttackPositionX,
        moveIntoAttackPositionY, origPositionX , origPositionY);

    SetCreatureFacingDirection *originalFacingDirection =
        new SetCreatureFacingDirection(initiator , LEFT);
    SetCreatureFacingDirection *attackFacingDirection =
        new SetCreatureFacingDirection(initiator , UP);

    ChangeCreatureImage *furyOfTheFang1 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("furyOfTheFang1"));
    ChangeCreatureImage *furyOfTheFang2 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("furyOfTheFang2"));
    ChangeCreatureImage *furyOfTheFang3 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("furyOfTheFang3"));
    ChangeCreatureImage *furyOfTheFang4 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("furyOfTheFang4"));
    ChangeCreatureImage *furyOfTheFang5 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("furyOfTheFang5"));
    ChangeCreatureImage *furyOfTheFang6 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("furyOfTheFang6"));
    ChangeCreatureImage *furyOfTheFang7 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("furyOfTheFang7"));
    ChangeCreatureImage *furyOfTheFang8 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("furyOfTheFang8"));
    ChangeCreatureImage *furyOfTheFang9 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("furyOfTheFang9"));
    ChangeCreatureImage *furyOfTheFang10 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("furyOfTheFang10"));
    ChangeCreatureImage *furyOfTheFang11 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("furyOfTheFang1"));

    ChangeCreatureImage *origImage = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("lancer"));

    ChangeCharacterWidth *increaseWidthForAttack = new ChangeCharacterWidth(
        initiator , 90);
    ChangeCharacterWidth *decreaseWidthToOriginalSize = new ChangeCharacterWidth(
        initiator , 32);

    ChangeCharacterHeight *increaseHeightForAttack = new ChangeCharacterHeight(
        initiator , 90);
    ChangeCharacterHeight *decreaseHeightToOriginalSize = new ChangeCharacterHeight(
        initiator , 32);

    DelayInSeconds *delay1 = new DelayInSeconds(.3);
    DelayInSeconds *delay2 = new DelayInSeconds(.2);
    DelayInSeconds *delay3 = new DelayInSeconds(.1);
    DelayInSeconds *delay4 = new DelayInSeconds(.3);
    DelayInSeconds *delay5 = new DelayInSeconds(.1);
    DelayInSeconds *delay6 = new DelayInSeconds(.1);
    DelayInSeconds *delay7 = new DelayInSeconds(.1);
    DelayInSeconds *delay8 = new DelayInSeconds(.1);
    DelayInSeconds *delay9 = new DelayInSeconds(.2);
    DelayInSeconds *delay10 = new DelayInSeconds(.3);
    DelayInSeconds *delay11 = new DelayInSeconds(.3);

    SimultaneousAnimations *attackSetup = new SimultaneousAnimations();
    attackSetup->loadAnimation(increaseWidthForAttack);
    attackSetup->loadAnimation(increaseHeightForAttack);
    attackSetup->loadAnimation(attackFacingDirection);
    attackSetup->loadAnimation(furyOfTheFang1);

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
    drawRepository->loadAnimation(delay1);
    drawRepository->loadAnimation(furyOfTheFang2);
    drawRepository->loadAnimation(delay2);
    drawRepository->loadAnimation(furyOfTheFang3);
    drawRepository->loadAnimation(delay3);
    drawRepository->loadAnimation(furyOfTheFang4);
    drawRepository->loadAnimation(delay4);
    drawRepository->loadAnimation(furyOfTheFang5);
    drawRepository->loadAnimation(delay5);
    drawRepository->loadAnimation(furyOfTheFang6);
    drawRepository->loadAnimation(delay6);
    drawRepository->loadAnimation(furyOfTheFang7);
    drawRepository->loadAnimation(delay7);
    drawRepository->loadAnimation(furyOfTheFang8);
    drawRepository->loadAnimation(delay8);
    drawRepository->loadAnimation(furyOfTheFang9);
    drawRepository->loadAnimation(delay9);
    drawRepository->loadAnimation(furyOfTheFang10);
    drawRepository->loadAnimation(delay10);
    drawRepository->loadAnimation(furyOfTheFang11);
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
void FuryOfTheFang::calculateDamage(){

    damageToReceiver = DamageCalculations::damageWithDelayAtk(
        initiator, receiver , 5 , 2.5);
}

//Sets the draw to spell location.
void FuryOfTheFang::setInitiatorAttackPosition(Character *initiator , 
    Character *receiver , int &moveIntoAttackPositionX ,
    int &moveIntoAttackPositionY){

    moveIntoAttackPositionX = receiver->getX() + receiver->getW();

    int initiatorHeight = 90; //Matches the size of the action image.

    //Receiver is taller than initiator.
    if(receiver->getH() > initiatorHeight){

        moveIntoAttackPositionY = receiver->getY() +
            ((receiver->getH() - initiatorHeight) / 2);
    }

    //Initiator is taller than receiver.
    else{
        moveIntoAttackPositionY = receiver->getY() -
            ((initiatorHeight - receiver->getH()) / 2);
    }
}