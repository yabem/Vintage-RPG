#include "Backstab.h"

//Default constructor.
Backstab::Backstab(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    drawRepository = NULL;
    damageToReceiver = 0;
}

//Destructor.
Backstab::~Backstab(){

    //Deletion is handled by the ImageStore.
}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void Backstab::loadCharacters(Character *initiator ,
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
void Backstab::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Determines the damage to the receiver.
    calculateDamage();

    //Remove receiver's hitpoints.
    receiver->addToRemainingHP(-damageToReceiver);

    loadAnimations();
}

//Loads the animations to the animations vector.
void Backstab::loadAnimations(){

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
    MovingCreature *backToStartingPosition = new MovingCreature(initiator , 10);
    
    setInitiatorAttackPosition(initiator , receiver , moveIntoAttackPositionX ,
        moveIntoAttackPositionY);

    positionBeforeAttack->initialize(origPositionX , origPositionY ,
        moveIntoAttackPositionX, moveIntoAttackPositionY);

    backToStartingPosition->initialize(moveIntoAttackPositionX,
        moveIntoAttackPositionY, origPositionX , origPositionY);

    SetCreatureFacingDirection *originalFacingDirection =
        new SetCreatureFacingDirection(initiator , LEFT);
    SetCreatureFacingDirection *attackFacingDirection =
        new SetCreatureFacingDirection(initiator , RIGHT);
    SetCreatureFacingDirection *stabFacingDirection =
        new SetCreatureFacingDirection(initiator , 0);

    ChangeCreatureImage *prepareStab = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefPrepareStab"));
    ChangeCreatureImage *thiefPrepareStabWindUp = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefPrepareStabWindUp"));
    ChangeCreatureImage *stab = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thiefStab"));
    ChangeCreatureImage *origImage = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("thief"));

    DelayInSeconds *delayAfterPrepare = new DelayInSeconds(.1);
    DelayInSeconds *delayAfterWindUp = new DelayInSeconds(.5);
    DelayInSeconds *delayAfterStab = new DelayInSeconds(.1);

    //Load all the animations to the animations queue.
    drawRepository->loadAnimation(positionBeforeAttack);
    drawRepository->loadAnimation(stabFacingDirection);
    drawRepository->loadAnimation(prepareStab);
    drawRepository->loadAnimation(delayAfterPrepare);
    drawRepository->loadAnimation(thiefPrepareStabWindUp);
    drawRepository->loadAnimation(delayAfterWindUp);
    drawRepository->loadAnimation(stab);
    drawRepository->loadAnimation(delayAfterStab);
    drawRepository->loadAnimation(damage);
    drawRepository->loadAnimation(damageStay); 
    drawRepository->loadAnimation(origImage); 
    drawRepository->loadAnimation(originalFacingDirection); 
    drawRepository->loadAnimation(backToStartingPosition); 
}

//Calculates the damage to the receiver.
//Pre:  None.
//Post: The initiator is the Character doing the attacking
//      The receiver is the Character receiving the attack.
//      The imageStore is where the images will be taken from.
void Backstab::calculateDamage(){

    damageToReceiver = DamageCalculations::damageWithDelay(
        initiator , receiver , 2 , 3.6);
}

//Sets the draw to spell location.
void Backstab::setInitiatorAttackPosition(Character *initiator , 
    Character *receiver , int &moveIntoAttackPositionX ,
    int &moveIntoAttackPositionY){

    moveIntoAttackPositionX = receiver->getX() - initiator->getW();

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