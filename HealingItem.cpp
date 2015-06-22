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

//Returns the items capacity.
int HealingItem::getCapacity(){

    return capacity;
}

//Adds to the current amount of the item.
//Pre:  None.
//Post: The amountToAdd is added to currentAmount. If the new amount
//      is > than the capacity, it will only be increased to the capacity
//      and will return true. If the new amount will be unchanged and will 
//      return false. If the amount is > 0 and < capacity, the amount
//      is added and returns true.
bool HealingItem::addToAmount(int amountToAdd){

    if(amountToAdd + currentAmount < 0){
        
        return false;
    }

    else if(amountToAdd + currentAmount > capacity){
        
        currentAmount = capacity;
        return true;
    }

    else {
        
        currentAmount += amountToAdd;
        return true;
    }
}