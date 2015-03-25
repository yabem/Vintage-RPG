//Money reward for when the Player defeats an enemy.

#pragma once
#include "I_Reward.h"
#include "I_List.h"
#include "GameConfig.h"
#include "Backpack.h"

class GainedMoney : public I_Reward{

private:

    int amountGained;
    Backpack *backpack;

public:

    GainedMoney(int amountOfPoints , Backpack *backpack);
    virtual ~GainedMoney();
    virtual bool deliverToPlayer();
    virtual std::string getName();
    virtual int getAmount();
};