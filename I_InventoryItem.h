//The interface for InventoryItems.

#pragma once
#include <string>

class I_InventoryItem{

private:

public:

    I_InventoryItem();
    virtual ~I_InventoryItem();
    virtual std::string getName() = 0;
    virtual int getAmount() = 0;
    virtual int getCapacity() = 0;
    virtual bool addToAmount(int amountToAdd) = 0;
};