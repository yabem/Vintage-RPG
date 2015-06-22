//An item that heals a player.

#pragma once
#include "I_InventoryItem.h"
#include "GameConfig.h"

class HealingItem : public I_InventoryItem{

private:

    std::string name;
    int currentAmount;
    int capacity;       //Total possible amount.

public:

    HealingItem(std::string name , int amount);
    virtual ~HealingItem();
    virtual std::string getName();
    virtual int getAmount();
    virtual int getCapacity();
    virtual bool addToAmount(int amountToAdd);
};