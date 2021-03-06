//CharacterAttack is an object that initiates an
//attack between one Character and AnotherCharacter
//using the approriate attack and defense stats.

#pragma once
#include "CharacterManipulation.h"
#include "Character.h"
#include "I_Animation.h"
#include <queue>
#include "MovingImage.h"
#include "MovingText.h"
#include "ImageStore.h"
#include "FontStore.h"
#include "DrawRepository.h"

class CharacterAttack : public CharacterManipulation{

private:

    int damageToReceiver;   //Total damage to the receiver.

public:

    CharacterAttack();      //Default constructor.
    ~CharacterAttack();     //Destructor.

    //Loads the Characters.
    void loadCharacters(Character *initiator , Character *receiver);

    //Initiates the attack action between the two characters.
    void execute();   

    //Loads the animations to the animations vector.
    void loadAnimations();

    //Calculates the damage to the receiver.
    void calculateDamage();

    //Returns a pointer to the Animation at the front of the list.
    I_Animation* getFrontAnimation();

    //Removes the pointer at the front of the Animation list.
    void removeFrontAnimation();

    //Checks if the Animation list is empty.
    bool animationsIsEmpty();
};