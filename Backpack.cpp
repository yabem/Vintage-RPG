#include "Backpack.h"

//Constructor.
Backpack::Backpack(){

    this->moneyBalance = 0;
}

//Destructor.
Backpack::~Backpack(){

}

int Backpack::getMoney(){

    return moneyBalance;
}

void Backpack::addMoney(int amountToAdd){

    moneyBalance += amountToAdd;
}

//Adds the item to the backpack.
//Pre:  The I_InventoryItem is valid.
//Post: If the I_InventoryItem does not exists, it is added.
//      If the I_InventoryItem already exists, the quantity is
//      added to the existing I_InventoryItem.
void Backpack::addItem(I_InventoryItem *i_InventoryItem){
    
    //Find the Reward if it exists.
    std::map<std::string , I_InventoryItem*>::iterator contentsIter =
        contents.find(i_InventoryItem->getName());
        
    //Reward does not exist in the summary so add it.
    if(contentsIter == contents.end()){

        contents.insert(std::pair<std::string , I_InventoryItem*>(
            i_InventoryItem->getName() , i_InventoryItem));
    }
        
    //Reward already exists so add the quantity.
    else (*contentsIter).second->addToAmount(i_InventoryItem->getAmount());
}