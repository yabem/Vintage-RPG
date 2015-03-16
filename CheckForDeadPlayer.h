//Checks in the player is dead. If it's dead then it sets
//the player to dead.

#pragma once
#include "I_Event.h"
#include "I_Creature.h"
#include "DrawRepository.h"

class CheckForDeadPlayer : public I_Event {

private:

    I_Creature *thePlayer;
    DrawRepository *drawRepository;

public:

    //Constructor.
    CheckForDeadPlayer(I_Creature *thePlayer , DrawRepository *drawRepository);

    //Destructor.
    ~CheckForDeadPlayer();

    //Executes the CheckForDeadPlayer.
    virtual bool execute();
};