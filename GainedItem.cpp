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
//Post: Delivers the experience points to the player.
bool GainedItem::deliverToPlayer(){

    //Fix memory leak, figure out how to delete this.
    I_InventoryItem *potion = new HealingItem("Potion" , amountGained);

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