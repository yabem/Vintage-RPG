#include "Jump.h"

//Default constructor.
Jump::Jump(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    drawRepository = NULL;
    damageToReceiver = 0;
}

//Destructor.
Jump::~Jump(){

    //Deletion is handled by the 
}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void Jump::loadCharacters(Character *initiator ,
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
void Jump::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Determines the damage to the receiver.
    calculateDamage();

    //Remove receiver's hitpoints.
    receiver->addToRemainingHP(-damageToReceiver);

    loadAnimations();
}

//Loads the animations to the animations vector.
void Jump::loadAnimations(){

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

    //Original location of the character.
    int saveX = initiator->getX();
    int saveY = initiator->getY();
    ALLEGRO_BITMAP *originalImage = imageStore->getBitMap("player");

    MovingCreature *jumpUp = new MovingCreature(initiator , 20);
    jumpUp->initialize(initiator->getX() , initiator->getY() ,
        initiator->getX() , -initiator->getH());

    MovingCreature *diveToEnemy = new MovingCreature(initiator , 10);
    diveToEnemy->initialize(initiator->getX() , -initiator->getH() * 2,
        receiver->getX() + (receiver->getW() / 2),
        (receiver->getY() + (receiver->getH() / 2)) - initiator->getH());

    MovingCreature *returnToOriginalSpot = new MovingCreature(initiator , 15);
    returnToOriginalSpot->initialize(initiator->getX() ,
        initiator->getY() , saveX , saveY);

    ChangeCreatureImage *kneel = new ChangeCreatureImage(initiator ,
        imageStore->getBitMap("playerKneel"));
    ChangeCreatureImage *jump = new ChangeCreatureImage(initiator ,
        imageStore->getBitMap("playerJump"));
    ChangeCreatureImage *diving = new ChangeCreatureImage(initiator ,
        imageStore->getBitMap("playerLanceDive"));
    ChangeCreatureImage *origImage = new ChangeCreatureImage(initiator ,
        imageStore->getBitMap("player"));

    SetCreatureFacingDirection *initialDirection = 
        new SetCreatureFacingDirection(initiator , 0);
    SetCreatureFacingDirection *endingDirection = 
        new SetCreatureFacingDirection(initiator , LEFT);

    DelayInSeconds *delayBeforeJump = new DelayInSeconds(.3);
    DelayInSeconds *delayAfterDive = new DelayInSeconds(.3);
    DelayInSeconds *delayAfterJump = new DelayInSeconds(.3);

    drawRepository->loadAnimation(initialDirection);
    drawRepository->loadAnimation(kneel);
    drawRepository->loadAnimation(delayBeforeJump);
    drawRepository->loadAnimation(jump);
    drawRepository->loadAnimation(jumpUp);
    drawRepository->loadAnimation(diving);
    drawRepository->loadAnimation(delayAfterJump);
    drawRepository->loadAnimation(diveToEnemy);
    drawRepository->loadAnimation(delayAfterDive);
    drawRepository->loadAnimation(damage);
    drawRepository->loadAnimation(damageStay); 
    drawRepository->loadAnimation(returnToOriginalSpot);
    drawRepository->loadAnimation(origImage);
    drawRepository->loadAnimation(endingDirection);
}

//Calculates the damage to the receiver.
//Pre:  None.
//Post: The initiator is the Character doing the attacking
//      The receiver is the Character receiving the attack.
//      The imageStore is where the images will be taken from.
void Jump::calculateDamage(){

    //Get attack and defense for calculation.
    int charAAttack = initiator->getAttack();
    int charBDefense = receiver->getDefense();

    damageToReceiver = charAAttack - charBDefense;

    //No damage done, the defense negated the attack.
    if(damageToReceiver < 0)
        damageToReceiver = 0;
}