//Holds the money and items for the player.

#pragma once
#include <map>
#include <string>
#include "I_InventoryItem.h"

class Backpack{

private:

    int moneyBalance;
    std::map<std::string , I_InventoryItem*> contents;

public:

    Backpack();
    ~Backpack();
    int getMoney();
    void addMoney(int amountToAdd);
    void addItem(I_InventoryItem *i_InventoryItem);
};