//An item that heals a player.

#pragma once
#include "I_InventoryItem.h"
#include "Enums.h"

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
    virtual void addToAmount(int amountToAdd);
};