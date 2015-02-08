//CharacterAttack is an object that initiates an
//attack between one Character and AnotherCharacter
//using the approriate attack and defense stats.

#pragma once
#include "CharacterManipulation.h"
#include "Character.h"
#include "Animation.h"
#include <queue>
#include "MovingImage.h"
#include "MovingText.h"
#include "ImageStore.h"

class CharacterAttack : public CharacterManipulation{

private:

    Character *initiator;   //Character that initiates the attack.
    Character *receiver;    //Character that receives the attack.
    ImageStore *imageStore; //Image store where the images will be retrieved.
    queue<Animation*> animations;    //Vector of animations.
    ALLEGRO_FONT *font;     //Font for the text.

    int damageToReceiver;   //Total damage to the receiver.

public:

    CharacterAttack();      //Default constructor.
    ~CharacterAttack();     //Destructor.

    //Initiates the attack action between the two characters.
    void execute();   

    //Initiates the attack between the two characters.
    void loadAttack(Character *initiator , Character *receiver ,
        ImageStore *imageStore , ALLEGRO_FONT *font);

    //Loads the animations to the animations vector.
    void loadAnimations();

    //Returns a pointer to the Animation at the front of the list.
    Animation* getFrontAnimation();

    //Removes the pointer at the front of the Animation list.
    void removeFrontAnimation();

    //Checks if the Animation list is empty.
    bool animationsIsEmpty();
};