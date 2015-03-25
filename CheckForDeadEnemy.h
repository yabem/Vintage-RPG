//Checks in the Enemy is dead. If it's dead then it sets
//the Enemy to dead.

#pragma once
#include "I_Event.h"
#include "I_Creature.h"
#include "I_Manager.h"
#include "DrawRepository.h"
#include "GainedExperiencePoints.h"
#include "GainedMoney.h"
#include "GainedItem.h"
#include "CalculateRewards.h"

class CheckForDeadEnemy : public I_Event {

private:

    I_Creature *theEnemy;
    DrawRepository *drawRepository;
    I_Manager *battleManager;

public:

    //Constructor.
    CheckForDeadEnemy(I_Creature *theEnemy , DrawRepository *drawRepository ,
        I_Manager *battleManager);

    //Destructor.
    ~CheckForDeadEnemy();

    //Executes the CheckForDeadEnemy.
    virtual bool execute();
};