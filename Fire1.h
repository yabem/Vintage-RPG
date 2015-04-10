//Fire1 is an object that initiates an
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

class Fire1 : public CharacterManipulation{

private:

    int damageToReceiver;   //Total damage to the receiver.

public:

    Fire1();      //Default constructor.
    ~Fire1();     //Destructor.

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
    void setSpellDestinationPosition(Character *initiator , 
        ALLEGRO_BITMAP *bmap , int &spellDestinationX , int &spellDestinationY);

    //Sets the spell's start position.
    void setSpellStartPosition(Character *initiator , 
        ALLEGRO_BITMAP *bmap , int &spellStartFromX , int &spellStartFromY ,
        int moveIntoAttackPositionX , int moveIntoAttackPositionY);
};