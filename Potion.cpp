//Heals the player.

#include "Potion.h"

//Default constructor.
Potion::Potion(){

    imageStore = NULL;
    fontStore = NULL;
    initiator = NULL;
    receiver = NULL;
    font = NULL;
    drawRepository = NULL;
    healingToReceiver = 0;
}

//Destructor.
Potion::~Potion(){

    //Deletion is handled by the ImageStore.
}

//Loads the Characters.
//Pre:  None.
//Post: loads the iniatiator and receiver.
void Potion::loadCharacters(Character *initiator ,
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
void Potion::execute(){

    if(initiator == NULL || receiver == NULL)
        return;

    //Determines the damage to the receiver.
    calculateHealing();

    receiver->addToRemainingHP(healingToReceiver);

    loadAnimations();
}

//Loads the animations to the animations vector.
void Potion::loadAnimations(){

    //Creates the text that will display the damage above the receiver.
    MovingText *healing = new MovingText(font , 10 , 10 , 8 , false);
    MovingText *healingStay = new MovingText(font , 10 , 10 , 16 , false);

    //Convert damage to string for display purposes.
    char theDamage[10];
    _itoa_s(healingToReceiver , theDamage , 10);

    //Sets the start and end coordinates.
    healing->initialize(theDamage , receiver->getX() , receiver->getY() , 
        receiver->getX() , receiver->getY() - 50);
    healingStay->initialize(theDamage , receiver->getX() , receiver->getY() , 
        receiver->getX() , receiver->getY());

    ALLEGRO_BITMAP *potionPart1 = imageStore->getBitMap("potionSparkleFirst");
    ALLEGRO_BITMAP *potionPart2 = imageStore->getBitMap("potionSparkleSecond");
    ALLEGRO_BITMAP *potionPart3 = imageStore->getBitMap("potionSparkleThird");
    ALLEGRO_BITMAP *potionPart4 = imageStore->getBitMap("potionSparkleFourth");

    int drawToX = receiver->getX();
    int drawToY = receiver->getY();
    int imageWidth = al_get_bitmap_width(potionPart1);
    int imageHeight = al_get_bitmap_height(potionPart1);

    MovingImage *potionAnimation1 = new MovingImage(potionPart1 ,
        imageWidth , imageHeight , 7);

    MovingImage *potionAnimation2 = new MovingImage(potionPart2 ,
        imageWidth , imageHeight , 7);

    MovingImage *potionAnimation3 = new MovingImage(potionPart3 ,
        imageWidth , imageHeight , 7);

    MovingImage *potionAnimation4 = new MovingImage(potionPart4 ,
        imageWidth , imageHeight , 7);

    //The fire will move from the initiator to the receiver.
    potionAnimation1->initialize(drawToX , drawToY , drawToX , drawToY);
    potionAnimation2->initialize(drawToX , drawToY , drawToX , drawToY);
    potionAnimation3->initialize(drawToX , drawToY , drawToX , drawToY);
    potionAnimation4->initialize(drawToX , drawToY , drawToX , drawToY);

    //Load all the animations to the animations queue.
    drawRepository->loadAnimation(potionAnimation1);
    drawRepository->loadAnimation(potionAnimation2);
    drawRepository->loadAnimation(potionAnimation3);
    drawRepository->loadAnimation(potionAnimation4);
    drawRepository->loadAnimation(healing);
    drawRepository->loadAnimation(healingStay);
}

//Calculates the healing that will be done to the receiver.
void Potion::calculateHealing(){

    float baseHealingAmount = 25;
    float healingAugmentAmount = initiator->getStats()->getTtlMgc() * 2;

    healingToReceiver = baseHealingAmount + healingAugmentAmount;
}