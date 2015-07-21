//ThrowRock is an object that initiates an
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
#include "MovingCreature.h"
#include "ChangeCreatureImage.h"
#include "SetCreatureFacingDirection.h"
#include "DelayInSeconds.h"

class Fire2 : public CharacterManipulation{

private:

    int damageToReceiver;   //Total damage to the receiver.

public:

    Fire2();      //Default constructor.
    ~Fire2();     //Destructor.

    //Loads the Characters.
    void loadCharacters(Character *initiator , Character *receiver);

    //Initiates the attack action between the two characters.
    void execute();   

    //Loads the animations to the animations vector.
    void loadAnimations();

    //Calculates the damage to the receiver.
    void calculateDamage();
};