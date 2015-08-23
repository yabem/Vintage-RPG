#include "GainedItem.h"

//Constructor.
GainedItem::GainedItem(std::string itemName , int amountGained ,
    Backpack *backpack){

    this->itemName = itemName;
    this->item = NULL;
    this->amountGained = amountGained;
    this->backpack = backpack;
}

//Destructor.
GainedItem::~GainedItem(){

}

//Delivers the reward to the player.
//Pre:  The object has been initialized.
//Post: Delivers the item to the player.
bool GainedItem::deliverToPlayer(){

    I_InventoryItem *potion = new GenericItem(this->itemName , amountGained);

    backpack->addItem(potion);

    return true;
}

//Returns the name of the reward.
//Pre:  None.
//Post: Returns the name of the reward.
std::string GainedItem::getName(){

    return itemName;
}

//Returns the XP that is stored in the reward.
//Pre:  None.
//Post: Returns the amount of money.
int GainedItem::getAmount(){

    return amountGained;
}