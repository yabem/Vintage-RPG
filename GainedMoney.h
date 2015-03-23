//Money reward for when the Player defeats an enemy.

#pragma once
#include "I_Reward.h"
#include "I_List.h"
#include "Enums.h"

class GainedMoney : public I_Reward{

private:

    int amountGained;
    I_List *listOfPlayers;

public:

    GainedMoney(int amountOfPoints);
    virtual ~GainedMoney();
    virtual bool deliverToPlayer();
    virtual std::string getName();
    virtual int getAmount();
};