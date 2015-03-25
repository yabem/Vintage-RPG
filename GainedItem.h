//Item reward for when the Player defeats an enemy.

#pragma once
#include "I_Reward.h"
#include "I_List.h"
#include "GameConfig.h"
#include "Backpack.h"
#include "I_InventoryItem.h"
#include "HealingItem.h"

class GainedItem : public I_Reward{

private:

    std::string itemName;
    I_InventoryItem *item;
    int amountGained;
    Backpack *backpack;

public:

    GainedItem(std::string itemName , int amountOfPoints , Backpack *backpack);
    virtual ~GainedItem();
    virtual bool deliverToPlayer();
    virtual std::string getName();
    virtual int getAmount();
};