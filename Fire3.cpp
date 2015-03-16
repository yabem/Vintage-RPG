//Fire3 is an object that holds two characters CharacterA and
//CharacterB and a set of instructions to take the attack and defense from
//the first character and applies it to the second. The damage
//that is leftover after reducing the defense of CharacterB
//is deducted from CharacterB's remaining hit points.

#include "Fire3.h"

//Default constructor.
Fire3::Fire3(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    drawRepository = NULL;
    damageToReceiver = 0;
}

//Destructor.
Fire3::~Fire3(){

    //Deletion is handled by the 

}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void Fire3::loadCharacters(Character *initiator ,
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
void Fire3::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Determines the damage to the receiver.
    calculateDamage();

    //Remove receiver's hitpoints.
    receiver->addToRemainingHP(-damageToReceiver);

    loadAnimations();
}

//Loads the animations to the animations vector.
void Fire3::loadAnimations(){

    ALLEGRO_BITMAP *bmap = imageStore->getBitMap("fire3");

    //Throws a rock between the initiator and the receiver.
    MovingImage *weaponAttack = new MovingImage(
        bmap , al_get_bitmap_width(bmap) , al_get_bitmap_height(bmap) , 30);
    
    //The rock will move from the initiator to the receiver.
    weaponAttack->initialize(initiator->getX() , initiator->getY() , 
        receiver->getX() , receiver->getY());

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

    //Load all the animations to the animations queue.
    drawRepository->loadAnimation(weaponAttack);
    drawRepository->loadAnimation(damage);
    drawRepository->loadAnimation(damageStay);   
}

//Calculates the damage to the receiver.
//Pre:  None.
//Post: The initiator is the Character doing the attacking
//      The receiver is the Character receiving the attack.
//      The imageStore is where the images will be taken from.
void Fire3::calculateDamage(){

    //Get attack and defense for calculation.
    int charAAttack = initiator->getAttack();
    int charBDefense = receiver->getDefense();

    damageToReceiver = charAAttack - charBDefense;

    //No damage done, the defense negated the attack.
    if(damageToReceiver < 0)
        damageToReceiver = 0;
}