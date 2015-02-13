//CharacterAttack is an object that holds two characters CharacterA and
//CharacterB and a set of instructions to take the attack and defense from
//the first character and applies it to the second. The damage
//that is leftover after reducing the defense of CharacterB
//is deducted from CharacterB's remaining hit points.

#include "CharacterAttack.h"

//Default constructor.
CharacterAttack::CharacterAttack(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    damageToReceiver = 0;
}

//Destructor.
CharacterAttack::~CharacterAttack(){

    if(!animations.empty()){

        delete animations.front();
        animations.pop();
    }
}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void CharacterAttack::loadCharacters(Character *initiator ,
    Character *receiver){

    this->initiator = initiator;
    this->receiver = receiver;
}

//Loads the two characters.
//Pre:  Both Characters have valid stats.
//Post: The initiator, receiver, and imageStore are loaded.
//      The initiator is the Character doing the attacking
//      The receiver is the Character receiving the attack.
//      The imageStore is where the images will be taken from.
void CharacterAttack::initialize(Character *initiator , 
    Character *receiver , ImageStore *imageStore , FontStore *fontStore ,
    std::queue<Animation*> destinationAnimationQueue){
    
    this->initiator = initiator;
    this->receiver = receiver;
    this->imageStore = imageStore;
    this->font = fontStore->getFont("default");
    this->animations = destinationAnimationQueue;

    //Get attack and defense for calculation.
    int charAAttack = initiator->getAttack();
    int charBDefense = receiver->getDefense();

    damageToReceiver = charAAttack - charBDefense;

    //No damage done, the defense negated the attack.
    if(damageToReceiver < 0)
        damageToReceiver = 0;
}
 
//Initiates the attack action between the two Characters.
//Pre:  Both characters have been loaded.
//Post: The initiator's attack is checked against the
//      receiver's defense. The attack that is leftover
//      after the defense is subtracted is then reduced
//      from the receiver's hitpoints. If the HP are reduced
//      to 0 or below, the Character will be dead.
void CharacterAttack::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Remove receiver's hitpoints.
    receiver->addToRemainingHP(-damageToReceiver);

    loadAnimations();
}

//Loads the animations to the animations vector.
void CharacterAttack::loadAnimations(){

    ALLEGRO_BITMAP *bmap = imageStore->getBitMap("swordAttack");

    //Creates a flying sword that will move from the upper right
    //hand corner of the screen to the receiver.
    MovingImage *weaponAttack = new MovingImage(
        bmap , al_get_bitmap_width(bmap) , al_get_bitmap_height(bmap) , 30);
    
    //Set the start and end coordinates for the animation.
    weaponAttack->initialize(SCREEN_W , 0 , receiver->getX() , receiver->getY());

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
    animations.push(weaponAttack);
    animations.push(damage);
    animations.push(damageStay);
}

//Returns the first animation from the queue.
//Pre:  The Animations queue has been loaded with Animation objects.
//Post: Returns a pointer to the animation in the front of the Animations
//      queue.
Animation* CharacterAttack::getFrontAnimation(){
    
    if(animations.empty())
        return NULL;

    return animations.front();
}

//Removes the pointer at the front of the Animation queue.
//Pre:  N/A
//Post: The front Animation pointer is removed from the queue.
void CharacterAttack::removeFrontAnimation(){

    if(animations.empty())
        return;

    else animations.pop();
}

//Checks if the Animation queue is empty.
//Pre:  N/A
//Post: Returns true if the queue is empty. Returns false if the
//      queue has at least one element.
bool CharacterAttack::animationsIsEmpty(){

    if(animations.empty())
        return true;

    else return false;
}