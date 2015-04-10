//The initiator bashes the receiver with the initiator's shield.

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

class ShieldBash : public CharacterManipulation{

private:

    int damageToReceiver;   //Total damage to the receiver.

public:

    ShieldBash();      //Default constructor.
    ~ShieldBash();     //Destructor.

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

    //Sets the spell's destination position.
    void setAttackDestinationPosition(Character *initiator , 
    Character *receiver , int &attackDestinationX , int &attackDestinationY);
};