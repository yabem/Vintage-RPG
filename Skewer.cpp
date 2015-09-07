#include "Skewer.h"

//Default constructor.
Skewer::Skewer(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    drawRepository = NULL;
    damageToReceiver = 0;
}

//Destructor.
Skewer::~Skewer(){

    //Deletion is handled by the ImageStore.
}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void Skewer::loadCharacters(Character *initiator ,
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
void Skewer::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Determines the damage to the receiver.
    calculateDamage();

    //Remove receiver's hitpoints.
    receiver->addToRemainingHP(-damageToReceiver);

    loadAnimations();
}

//Loads the animations to the animations vector.
void Skewer::loadAnimations(){

    //Creates the text that will display the damage above the receiver.
    MovingText *damage = new MovingText(font , 10 , 10 , 8 , false);
    MovingText *damageStay = new MovingText(font , 10 , 10 , 16 , false);

    //Convert damage to string for display purposes.
    char theDamage[10];
    _itoa_s(damageToReceiver , theDamage , 10);

    //Sets the start and end coordinates.
    damage->initialize(theDamage , receiver->getX() , receiver->getY() , 
        receiver->getX() , receiver->getY() - 50);
    damageStay->initialize(theDamage , receiver->getX() , receiver->getY() , 
        receiver->getX() , receiver->getY());
    
    int origPositionX = initiator->getX();
    int origPositionY = initiator->getY();
    int moveIntoAttackPositionX = 0;
    int moveIntoAttackPositionY = 0;
    int attackDestinationX = 0;
    int attackDestinationY = 0;

    MovingCreature *positionBeforeAttack = new MovingCreature(initiator , 10);
    MovingCreature *executingTheAttack = new MovingCreature(initiator , 10);
    MovingCreature *backToStartingPosition = new MovingCreature(initiator , 10);
    
    setInitiatorAttackPosition(initiator , receiver , moveIntoAttackPositionX ,
        moveIntoAttackPositionY);

    positionBeforeAttack->initialize(origPositionX , origPositionY ,
        moveIntoAttackPositionX, moveIntoAttackPositionY);

    setAttackDestinationPosition(initiator , receiver , attackDestinationX , 
        attackDestinationY);
    
    executingTheAttack->initialize(moveIntoAttackPositionX , 
        moveIntoAttackPositionY , attackDestinationX, attackDestinationY);

    backToStartingPosition->initialize(moveIntoAttackPositionX,
        moveIntoAttackPositionY, origPositionX , origPositionY);
    
    SetCreatureFacingDirection *originalFacingDirection =
        new SetCreatureFacingDirection(initiator , LEFT);
    SetCreatureFacingDirection *attackFacingDirection =
        new SetCreatureFacingDirection(initiator , 0);

    ChangeCreatureImage *skewerPart1 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("skewerPart1"));
    ChangeCreatureImage *skewerPart2 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("skewerPart2"));
    ChangeCreatureImage *skewerPart3 = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("skewerPart3"));
    ChangeCreatureImage *player = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("lancer"));

    ChangeCharacterWidth *increaseWidthForAttack = new ChangeCharacterWidth(
        initiator , 66);
    ChangeCharacterWidth *decreaseWidthToOriginalSize = new ChangeCharacterWidth(
        initiator , 32);

    DelayInSeconds *delay1 = new DelayInSeconds(.3);
    DelayInSeconds *delay2 = new DelayInSeconds(.3);
    DelayInSeconds *delay3 = new DelayInSeconds(.3);

    SimultaneousAnimations *attackSetup = new SimultaneousAnimations();
    attackSetup->loadAnimation(increaseWidthForAttack);
    attackSetup->loadAnimation(attackFacingDirection);
    attackSetup->loadAnimation(positionBeforeAttack);
    attackSetup->loadAnimation(skewerPart1);

    SimultaneousAnimations *resetToOriginalPosition = new SimultaneousAnimations();
    resetToOriginalPosition->loadAnimation(decreaseWidthToOriginalSize);
    resetToOriginalPosition->loadAnimation(player);
    resetToOriginalPosition->loadAnimation(originalFacingDirection);
    resetToOriginalPosition->loadAnimation(backToStartingPosition);

    //Load all the animations to the animations queue.
    drawRepository->loadAnimation(attackSetup);

    drawRepository->loadAnimation(delay1);
    drawRepository->loadAnimation(skewerPart2);
    drawRepository->loadAnimation(delay2);
    drawRepository->loadAnimation(skewerPart3);
    drawRepository->loadAnimation(executingTheAttack);
    drawRepository->loadAnimation(delay3);
    drawRepository->loadAnimation(damage);
    drawRepository->loadAnimation(damageStay); 

    drawRepository->loadAnimation(resetToOriginalPosition);
}

//Calculates the damage to the receiver.
//Pre:  None.
//Post: The initiator is the Character doing the attacking
//      The receiver is the Character receiving the attack.
//      The imageStore is where the images will be taken from.
void Skewer::calculateDamage(){

    damageToReceiver = DamageCalculations::damageWithDelayAtk(
        initiator , receiver , 1.875 , 1.5);
}

//Sets the draw to spell location.
void Skewer::setInitiatorAttackPosition(Character *initiator , 
    Character *receiver , int &moveIntoAttackPositionX ,
    int &moveIntoAttackPositionY){

    moveIntoAttackPositionX = receiver->getX() + SCREEN_W / 2;

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

//Sets the attack's destination position.
void Skewer::setAttackDestinationPosition(Character *initiator , 
    Character *receiver , int &attackDestinationX , int &attackDestinationY){

    attackDestinationX = receiver->getX();

    //Receiver is taller than initiator.
    if(receiver->getH() > initiator->getH()){
        
        attackDestinationY = receiver->getY() +
            ((receiver->getH() - initiator->getH()) / 2);
    }

    //The spell is taller than receiver.
    else{

        attackDestinationY = receiver->getY() -
            ((initiator->getH()- receiver->getH()) / 2);
    }
}