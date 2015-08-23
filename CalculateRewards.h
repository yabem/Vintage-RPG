//Calculates the rewards after the battles based off of the enemies.

#pragma once
#include "I_Manager.h"
#include "I_Creature.h"
#include "GainedExperiencePoints.h"
#include "GainedItem.h"
#include "GainedMoney.h"
#include "I_InventoryItem.h"
#include "GenericItem.h"

class CalculateRewards{

private:

    I_Manager *battleManager;
    I_Creature *theEnemy;

    void deliverMoney();
    void deliverXP();
    void deliverItems();

    //Calculates the reward items based off of the enemy killed.
    void getItemRewards();

public:
    CalculateRewards(I_Manager *battleManager , I_Creature *theEnemy);
    ~CalculateRewards();

    void deliverAllRewards();
};