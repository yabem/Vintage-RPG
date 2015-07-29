//EarthShatter positions the character in the middle of the screen
//then attacks the enemy at range for damage.

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
#include "Conversion.h"
#include "ChangeCharacterWidth.h"
#include "ChangeCharacterHeight.h"
#include "SimultaneousAnimations.h"
#include "DamageCalculations.h"

class EarthShatter : public CharacterManipulation{

private:

    int damageToReceiver;   //Total damage to the receiver.

public:

    EarthShatter();      //Default constructor.
    ~EarthShatter();     //Destructor.

    //Loads the Characters.
    void loadCharacters(Character *initiator , Character *receiver);

    //Initiates the attack action between the two characters.
    void execute();   

    //Loads the animations to the animations vector.
    void loadAnimations();

    //Calculates the damage to the receiver.
    void calculateDamage();

    //Sets the ititiator's attack position.
    void setInitiatorAttackPosition(Character *initiator , Character *receiver ,
        int &moveIntoAttackPositionX , int &moveIntoAttackPositionY);
};