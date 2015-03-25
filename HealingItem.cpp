#include "HealingItem.h"

//Constructor.
HealingItem::HealingItem(std::string name , int amount){

    this->name = name;
    this->currentAmount = 0;
    this->capacity = DEFAULT_ITEM_CAPACITY;

    //Sets currentAmount.
    addToAmount(amount);
}

//Destructor.
HealingItem::~HealingItem(){

}

//Returns the name of the item.
std::string HealingItem::getName(){

    return this->name;
}

//Returns the current amount of the item.
int HealingItem::getAmount(){

    return currentAmount;
}

//Adds to the current amount of the item.
//Pre:  None.
//Post: The amountToAdd is added to currentAmount. If the new amount
//      is > than the capacity, it will only be increased to the capacity.
//      If the new capacity is < 0, the capacity will be set to 0.
void HealingItem::addToAmount(int amountToAdd){

    if(amountToAdd + currentAmount < 0)
        currentAmount = 0;

    else if(amountToAdd + currentAmount > capacity)
        currentAmount = capacity;

    else currentAmount += amountToAdd;
}