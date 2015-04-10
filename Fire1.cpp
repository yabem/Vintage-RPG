//Fire1 is an object that holds two characters CharacterA and
//CharacterB and a set of instructions to take the attack and defense from
//the first character and applies it to the second. The damage
//that is leftover after reducing the defense of CharacterB
//is deducted from CharacterB's remaining hit points.

#include "Fire1.h"

//Default constructor.
Fire1::Fire1(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    drawRepository = NULL;
    damageToReceiver = 0;
}

//Destructor.
Fire1::~Fire1(){

    //Deletion is handled by the ImageStore.
}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void Fire1::loadCharacters(Character *initiator ,
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
void Fire1::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Determines the damage to the receiver.
    calculateDamage();

    //Remove receiver's hitpoints.
    receiver->addToRemainingHP(-damageToReceiver);

    loadAnimations();
}

//Loads the animations to the animations vector.
void Fire1::loadAnimations(){

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

    MovingCreature *positionBeforeAttack = new MovingCreature(initiator , 10);
    MovingCreature *backToStartingPosition = new MovingCreature(initiator , 10);
    
    setInitiatorAttackPosition(initiator , receiver , moveIntoAttackPositionX ,
        moveIntoAttackPositionY);

    positionBeforeAttack->initialize(origPositionX , origPositionY ,
        moveIntoAttackPositionX, moveIntoAttackPositionY);

    backToStartingPosition->initialize(moveIntoAttackPositionX,
        moveIntoAttackPositionY, origPositionX , origPositionY);

    ALLEGRO_BITMAP *bmap = imageStore->getBitMap("fire1");
    int spellDestinationX = 0;
    int spellDestinationY = 0;

    setSpellDestinationPosition(initiator , bmap , spellDestinationX , 
        spellDestinationY);

    int spellStartFromX = 0;
    int spellStartFromY = 0;

    setSpellStartPosition(initiator , bmap , spellStartFromX , spellStartFromY ,
        moveIntoAttackPositionX , moveIntoAttackPositionY);

    //Throws a fire1 between the initiator and the receiver.
    MovingImage *weaponAttack = new MovingImage(
        bmap , al_get_bitmap_width(bmap) , al_get_bitmap_height(bmap) , 15);

    //The fire will move from the initiator to the receiver.
    weaponAttack->initialize(spellStartFromX , 
        spellStartFromY , spellDestinationX , spellDestinationY);
    
    SetCreatureFacingDirection *originalFacingDirection =
        new SetCreatureFacingDirection(initiator , LEFT);
    SetCreatureFacingDirection *attackFacingDirection =
        new SetCreatureFacingDirection(initiator , 0);

    ChangeCreatureImage *prepareSpell = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("magePrepareSpell"));
    ChangeCreatureImage *castSpell = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mageCastSpell"));
    ChangeCreatureImage *origImage = new ChangeCreatureImage(initiator
        , imageStore->getBitMap("mage"));

    DelayInSeconds *delayForSpellPrep = new DelayInSeconds(.3);

    //Load all the animations to the animations queue.
    drawRepository->loadAnimation(positionBeforeAttack);
    drawRepository->loadAnimation(attackFacingDirection);
    drawRepository->loadAnimation(prepareSpell);
    drawRepository->loadAnimation(delayForSpellPrep);
    drawRepository->loadAnimation(castSpell);
    drawRepository->loadAnimation(weaponAttack);
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
void Fire1::calculateDamage(){

    //Get attack and defense for calculation.
    int charAAttack = initiator->getAttack();
    int charBDefense = receiver->getDefense();

    damageToReceiver = charAAttack - charBDefense;

    //No damage done, the defense negated the attack.
    if(damageToReceiver < 0)
        damageToReceiver = 0;
}

//Sets the draw to spell location.
void Fire1::setInitiatorAttackPosition(Character *initiator , 
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

//Sets the spell's destination position.
void Fire1::setSpellDestinationPosition(Character *initiator , 
    ALLEGRO_BITMAP *bmap , int &spellDestinationX , int &spellDestinationY){

    spellDestinationX = receiver->getX();

    //Receiver is taller than spell.
    if(receiver->getH() > al_get_bitmap_height(bmap)){
        
        spellDestinationY = receiver->getY() +
            ((receiver->getH() - al_get_bitmap_height(bmap)) / 2);
    }

    //The spell is taller than receiver.
    else{

        spellDestinationY = receiver->getY() -
            ((al_get_bitmap_height(bmap) - receiver->getH()) / 2);
    }
}

//Sets the spell's start position.
void Fire1::setSpellStartPosition(Character *initiator , 
    ALLEGRO_BITMAP *bmap , int &spellStartFromX , int &spellStartFromY ,
    int moveIntoAttackPositionX , int moveIntoAttackPositionY){

    spellStartFromX = moveIntoAttackPositionX - al_get_bitmap_width(bmap);

    //Initiator is taller than spell.
    if(initiator->getH() > al_get_bitmap_height(bmap)){

        spellStartFromY = moveIntoAttackPositionY +
            ((al_get_bitmap_height(bmap) - initiator->getH()) / 2);
    }

    //The spell is taller than initiator.
    else{

        spellStartFromY = moveIntoAttackPositionY -
            ((al_get_bitmap_height(bmap) - initiator->getH()) / 2);
    }
}