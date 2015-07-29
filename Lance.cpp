#include "Lance.h"

//Default constructor.
Lance::Lance(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    drawRepository = NULL;
    damageToReceiver = 0;
}

//Destructor.
Lance::~Lance(){

    //Deletion is handled by the ImageStore.
}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void Lance::loadCharacters(Character *initiator ,
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
void Lance::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Determines the damage to the receiver.
    calculateDamage();

    //Remove receiver's hitpoints.
    receiver->addToRemainingHP(-damageToReceiver);

    loadAnimations();
}

//Loads the animations to the animations vector.
void Lance::loadAnimations(){

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

    ChangeCreatureImage *lancerAttackPart1 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("lancerAttackPart1"));
    ChangeCreatureImage *lancerAttackPart2 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("lancerAttackPart2"));
    ChangeCreatureImage *origImage = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("lancer"));

    ChangeCharacterWidth *increaseWidthForAttack = new ChangeCharacterWidth(
        initiator , 60);
    ChangeCharacterWidth *decreaseWidthToOriginalSize = new ChangeCharacterWidth(
        initiator , 32);

    DelayInSeconds *delaylancerAttackPart1 = new DelayInSeconds(.3);
    DelayInSeconds *delaylancerAttackPart2 = new DelayInSeconds(.2);

    SimultaneousAnimations *attackSetup = new SimultaneousAnimations();
    attackSetup->loadAnimation(increaseWidthForAttack);
    attackSetup->loadAnimation(attackFacingDirection);
    attackSetup->loadAnimation(lancerAttackPart1);

    SimultaneousAnimations *resetToOriginalPosition = new SimultaneousAnimations();
    resetToOriginalPosition->loadAnimation(decreaseWidthToOriginalSize);
    resetToOriginalPosition->loadAnimation(origImage);
    resetToOriginalPosition->loadAnimation(originalFacingDirection);
    resetToOriginalPosition->loadAnimation(backToStartingPosition);

    //Load all the animations to the animations queue.
    drawRepository->loadAnimation(attackSetup);

    drawRepository->loadAnimation(positionBeforeAttack);
    drawRepository->loadAnimation(moveUpForAttack);
    drawRepository->loadAnimation(delaylancerAttackPart1);
    drawRepository->loadAnimation(lancerAttackPart2);
    drawRepository->loadAnimation(delaylancerAttackPart2);
    drawRepository->loadAnimation(damage);
    drawRepository->loadAnimation(damageStay); 

    drawRepository->loadAnimation(resetToOriginalPosition);
}

//Calculates the damage to the receiver.
//Pre:  None.
//Post: The initiator is the Character doing the attacking
//      The receiver is the Character receiving the attack.
//      The imageStore is where the images will be taken from.
void Lance::calculateDamage(){

    //Get attack and defense for calculation.
    damageToReceiver = DamageCalculations::damageWithoutDelay(initiator, receiver);
}

//Sets the draw to spell location.
void Lance::setInitiatorAttackPosition(Character *initiator , 
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