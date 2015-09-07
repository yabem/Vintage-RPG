#pragma once
#include "I_InventoryItem.h"
#include "GameConfig.h"

class GenericItem : public I_InventoryItem{

private:

    std::string name;
    int currentAmount;
    int capacity;       //Total possible amount.

public:

    GenericItem(std::string name , int amount);
    virtual ~GenericItem();
    virtual std::string getName();
    virtual int getAmount();
    virtual int getCapacity();
    virtual bool addToAmount(int amountToAdd);
};