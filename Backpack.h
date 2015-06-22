//Holds the money and items for the player.

#pragma once
#include <map>
#include <string>
#include <vector>
#include "I_InventoryItem.h"
#include "InfoTable.h"
#include "FontStore.h"

class Backpack{

private:

    int moneyBalance;
    std::map<std::string , I_InventoryItem*> contents;
    std::vector<I_InventoryItem*> sortedContents;
    InfoTable *inventoryDisplay;
    FontStore *fontStore;

public:

    Backpack(FontStore *fontStore);
    ~Backpack();
    int getMoney();
    int getAmountInInventory(std::string itemName);
    bool itemExistsInInventory(std::string itemName);
    void addMoney(int amountToAdd);
    void addItem(I_InventoryItem *i_InventoryItem);
    void insertItemIntoSortedContents(I_InventoryItem *i_InventoryItem);
    bool adjustItemQuantity(std::string itemName , int quantityToAdjust);
    void removeAllContents();
    void updateInventoryDisplay();
    void centerInventoryDisplayToScreen();
    void displayInventory();
};